#include <chrono>
#include "world/World.h"
#include "world/worldRender.h"
#include "blockID.h"
#include "world/World.h"
#include "chests.h"
#include "furnaceHandler.h"
#include "graphics/graphics.h"
#include "graphics/interfaces/interfaceHandler.h"
#include "inventory.h"
#include "blockName.h"
#include "blocks.h"
#include "mainGame.h"
#include "mining.h"
#include "Config.h"
#include "general.h"
#include "mobs/mobHandler.h"
#include "mobs/hurt.h"
#include "blockPages.h"
#include "blockUpdaters/WaterUpdater.h"
#include "communications.h"

bool miningDisabled = false;
int framesOnBlock;
int framesTillBreak;
int targetSum = -1;
unsigned char soundOffset;
bool layerIsBG; //Layer of mined block
bool finishedTask = false;

void setMiningDisabled(bool set) //false enables block destroy, true disable it
{
	miningDisabled = set;
}

bool canMine() //Returns whether touch input can destroy blocks
{
	return !miningDisabled;
}

void destroyBlock(World &world, int x, int y, bool bg, bool byHand, bool updateBrightness)
{
	int blockID = getHandID();
	short *blockXY = bg ? &world.bgblocks[x][y] : &world.blocks[x][y];
	if (*blockXY == AIR)
		return;
	switch (*blockXY)
	{
	case CHEST:
		destroyChest(world, x, y, bg);
		break;
	case FURNACE:
	case FURNACE_LIT:
		destroyFurnace(world, x, y, bg);
		break;
	case WATER:
		if (blockID == BUCKET_EMPTY)
			fillBucket(world, x, y);
		break;
	default:
		if (!byHand || canBreak(*blockXY))
		{
			if (!byHand || canDropItem(*blockXY))
				createItemMob(x, y, getSurvivalItem(*blockXY));
			else if (!isSurvival())
				addInventory(getGenericBlock(*blockXY));
			*blockXY = AIR;
		}
		break;
	}
	if (updateBrightness)
		calculateBrightness(world, getPlayerPtr()->x / 16, getPlayerPtr()->y / 16);
	updateAround(world, x, y);
}

void placeBlock(World &world, int x, int y, bool bg)
{
	int blockID = getHandID();
	if (isFoodStuff(blockID))
	{
		BaseMob::Ptr m;
		m = mobHandlerFindMob(2000, MOB_PLAYER, x * 16, y * 16);
		if (m != nullptr)
		{
			m->health += getFoodValue(blockID);
			subInventory(blockID, 1);
		}
		return;
	}
	if (item(blockID) && !isPlaceableItem(blockID))
		return;
	if (subInventory(blockID, 1))
	{
		switch (blockID)
		{
		case CHEST:
			createChest(world, x, y, bg);
			break;
		case FURNACE:
		case FURNACE_LIT:
			createFurnace(world, x, y, bg);
			break;
		case BUCKET_WATER:
			createWaterMob(x, y);
			addInventory(BUCKET_EMPTY);
			break;
		case BUCKET_EMPTY:
			addInventory(BUCKET_EMPTY);
			break;
		default:
			if (!item(blockID))
			{
				if (bg)
					world.bgblocks[x][y] = blockID;
				else
					world.blocks[x][y] = blockID;
			}
			break;
		}
	}
	calculateBrightness(world, getPlayerPtr()->x / 16, getPlayerPtr()->y / 16);
	updateAround(world, x, y);
}

int destroyTime(int blockID, int selectedBlock) //Calculated the required frames to destroy a block
{
	if (!isSurvival())
		return 0;
	int handHardness = (getHardness(selectedBlock) < 0) ? getHardness(selectedBlock)*-1 : 1; // Hardness of item in hand
	int blockTypeXY = getType(blockID);
	switch (getType(selectedBlock)) //Ensures tools only work for correct material
	{
	case TYPE_AXE:
		if (blockTypeXY != TYPE_WOOD) handHardness = 1;
		break;
	case TYPE_PICKAXE:
		if (blockTypeXY != TYPE_STONE) handHardness = 1;
		break;
	case TYPE_SHOVEL:
		if (blockTypeXY != TYPE_SOIL) handHardness = 1;
		break;
	}
	int val = getHardness(blockID)*10 / handHardness;
	if (val > ACTIVATE_DELAY)
		return val;
	else
		return ACTIVATE_DELAY;
}

void changeTarget(int newSum, int newBlock)
{
	targetSum = newSum;
	framesTillBreak = destroyTime(newBlock, getHandID());
	framesOnBlock = 0;
	finishedTask = false;
	soundOffset = getTime() % HIT_SOUND_DELAY;
}

void activateBlock(World &world, int x, int y, bool bg)
{
	switch (bg ? world.bgblocks[x][y] : world.blocks[x][y])
	{
	case AIR:
	{
		placeBlock(world, x, y, bg);
		playBlockSfx(bg ? world.bgblocks[x][y] : world.blocks[x][y], SOUND_TYPE_PLACE, 255, getBlockPanning(x, world.camX));
		break;
	}
	case TNT:
	{
		bool skipWait = false;
		short &blockXY = bg ? world.bgblocks[x][y] : world.blocks[x][y];
		blockXY = GLOWSTONE;
		calculateBrightness(world, getPlayerPtr()->x / 16, getPlayerPtr()->y / 16);
		blockXY = TNT;
		playSound(SOUND_EXPLODE,230 + rand()%26, std::max(0, x * 16 - world.camX));
		vBlank();
		worldRender_Render(world);
		auto begin = std::chrono::high_resolution_clock::now();
		blockXY = AIR;
		for (int i = 0; i < 18; ++i)
		{
			const int SCALE = 1000;
			int xPos = x * SCALE, yPos = y * SCALE;
			int dx = rand() % SCALE;
			int dy = SCALE - dx;
			dx *= (rand() % 2) * 2 - 1;
			dy *= (rand() % 2) * 2 - 1;

			for (int fuel = 3 * SCALE ; fuel > 0;)
			{
				xPos += dx;
				yPos += dy;

				const short &BLOCK = bg ?
						world.bgblocks[xPos / SCALE][yPos / SCALE] :
						world.blocks[xPos / SCALE][yPos / SCALE];
				if (BLOCK == TNT)
				{
					skipWait = true;
					activateBlock(world, xPos / SCALE, yPos / SCALE, bg);
				}
				
				fuel -= SCALE;
				destroyBlock(world, xPos / SCALE, yPos / SCALE, bg, false);
			}
		}
		calculateBrightness(world, getPlayerPtr()->x / 16, getPlayerPtr()->y / 16);
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		auto frames = ms / (1000 / FPS);
		if (!skipWait)
			for (int i = 6 - frames; i > 0; --i)
				vBlank();
		break;
	}
	case CRAFTING_TABLE:
		setInterface(world, INTERFACE_CRAFTING, true);
		lcdMainOnTop();
		setMiningDisabled(true);
		break;
	case CHEST:
		openChest(world, x, y, bg);
		break;
	case FURNACE:
	case FURNACE_LIT:
		openFurnace(world, x, y, bg);
		break;
	case DOOR_OPEN_BOTTOM:
		--y;
	case DOOR_OPEN_TOP:
	{
		short &blockXY = bg ? world.bgblocks[x][y] : world.blocks[x][y];
		short &blockBelowXY = bg ? world.bgblocks[x][y + 1] : world.blocks[x][y + 1];
		blockXY = DOOR_CLOSED_TOP;
		blockBelowXY = DOOR_CLOSED_BOTTOM;
		playSound(SOUND_DOOR_CLOSE, 255, getBlockPanning(x, world.camX));
		calculateBrightness(world, getPlayerPtr()->x / 16, getPlayerPtr()->y / 16);
		break;
	}
	case DOOR_CLOSED_BOTTOM:
		--y;
	case DOOR_CLOSED_TOP:
	{
		short &blockXY = bg ? world.bgblocks[x][y] : world.blocks[x][y];
		short &blockBelowXY = bg ? world.bgblocks[x][y + 1] : world.blocks[x][y + 1];
		blockXY = DOOR_OPEN_TOP;
		blockBelowXY = DOOR_OPEN_BOTTOM;
		playSound(SOUND_DOOR_OPEN, 255, getBlockPanning(x, world.camX));
		calculateBrightness(world, getPlayerPtr()->x / 16, getPlayerPtr()->y / 16);
		break;
	}
	case WATER:
	{
		if (bg)
			return;
		if (getHandID() == BUCKET_EMPTY)
		{
			fillBucket(world, x, y);
			break;
		}
		int newLevel = pushWaterFrom(world, x, y);
		if (newLevel == 0)
		{
			placeBlock(world, x, y, bg);
			if (world.blocks[x][y] == WATER)
				world.blocks[x][y] = AIR;
		}
		else
			setWaterLevel(world, x, y, newLevel);
		break;
	}
	default:
		if (!isSurvival())
			destroyBlock(world, x, y, bg);
		break;
	}
}

bool attackMob(World &world, int px, int py)
{
	BaseMob::Ptr targetMob = isMobAt(px + world.camX, py + world.camY);
	if (targetMob != nullptr)
	{
		int damage;
		switch (getHandID())
		{
		case SWORD_DIAMOND:
			damage = 6;
			break;
		case SWORD_IRON:
			damage = 4;
			break;
		case SWORD_GOLD:
			damage = 3;
			break;
		case SWORD_STONE:
			damage = 3;
			break;
		case SWORD_WOOD:
			damage = 2;
			break;
		default:
			damage = 1;
			break;
		}
		targetMob->hurt(damage, PLAYER_HURT);
		return true;
	}
	else
		return false;
}

void miningUpdate(World &world, touchPosition touch)
{
	int x = (touch.px - 1 + world.camX) / 16;
	int y = (touch.py - 1 + world.camY) / 16;
	if (!(keysHeld() & KEY_TOUCH) || miningDisabled)
	{
		if (targetSum != -1)
		{
			if (!finishedTask && framesOnBlock < ACTIVATE_DELAY)
				activateBlock(world, x, y, keysHeld() & getGlobalSettings()->getKey(ACTION_CROUCH));
			targetSum = -1;
			finishedTask = false;
		}
		return;
	}
	int touchedBlock;
	bool oldLayerIsBG = layerIsBG;
	if ((world.blocks[x][y] == AIR && isSurvival()) || (isBlockWalkThrough(world.blocks[x][y])
			&& keysHeld() & getGlobalSettings()->getKey(ACTION_CROUCH)))
	{
		touchedBlock = world.bgblocks[x][y];
		layerIsBG = true;
	}
	else if (!(keysHeld() & getGlobalSettings()->getKey(ACTION_CROUCH)))
	{
		touchedBlock = world.blocks[x][y];
		layerIsBG = false;
	}
	else
		touchedBlock = AIR;
	if (targetSum != x + y || (oldLayerIsBG != layerIsBG && !finishedTask)) //Changed block
	{
		if (attackMob(world, touch.px, touch.py))
			finishedTask = true;
		else
			changeTarget(x + y, touchedBlock);
	}
	if (touchedBlock != AIR && framesOnBlock >= framesTillBreak && !finishedTask && framesOnBlock >= ACTIVATE_DELAY)
	{
		destroyBlock(world, x, y, world.blocks[x][y] == AIR || keysHeld() & getGlobalSettings()->getKey(ACTION_CROUCH));
		changeTarget(x + y, AIR);
		finishedTask = true;
		playBlockSfx(touchedBlock, SOUND_TYPE_DESTROY, 255, touch.px);
	}
	if (touchedBlock != AIR && !finishedTask)
	{
		++framesOnBlock;
		if ((getTime() - soundOffset) % HIT_SOUND_DELAY == 0)
			playBlockSfx(touchedBlock, SOUND_TYPE_DESTROY, 80, touch.px);
	}

}
