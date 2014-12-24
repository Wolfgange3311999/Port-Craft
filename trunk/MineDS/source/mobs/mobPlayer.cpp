#include <string>
#include "hurt.h"
#include "../nifi.h"
#include "../blocks.h"
#include "../worldRender.h"
#include "../graphics/graphics.h"
#include "../inventory.h"
#include "mobPlayer.h"
#include "../general.h"
#include "../blockID.h"
#include "../sounds.h"
#include "../deathScreen.h"
#include "../mainGame.h"
#include "../graphics/inventoryGraphics.h"
#include "../Config.h"
#include <time.h>
//ASDF?
//
#define PLAYER_FULL_HEALTH 20
#define PLAYER_SPRITE_WALK 0
#define PLAYER_SPRITE_HURT 1
#define PLAYER_SPRITE_MINE 2
bool quitGame = false;
int slow = 0;
Graphic playerMobGraphic[3];
Graphic hearts[2];

bool shouldQuitGame()
{
	return quitGame;
}

playerMob::playerMob()
{
	x = 0;
	y = 0;
	vy = 0;
	vx = 0;
	alive = false;
	onground = false;
	facing = 0;
	animation = 0;
	mobtype = 2;
	health = PLAYER_FULL_HEALTH;
	ping = 0;
	reheal = 0;
	tillBrightness = 0;
	deathscreen = false;
	quitGame = false;
}

playerMob::playerMob(int a, int b)
{
	gravity = 3;
	gravityValue = 3;
	sx = 6;
	sy = 32;
	x = a;
	y = b;
	vy = 0;
	vx = 0;
	alive = false;
	onground = false;
	facing = false;
	mobtype = 2;
	health = PLAYER_FULL_HEALTH;
	ping = 0;
	animation = 0;
	timeTillWifiUpdate = rand() % 4 + 4;
	reheal = 0;
	tillBrightness = 0;
	deathscreen = false;
	quitGame = false;
}

void playerMob::hurt(int amount, int type)
{
	if (isSurvival() || type == VOID_HURT)
	{
		if (animation == 1)
			return;
		if (type != VOID_HURT)
			vy -= 2;
		playSound(SOUND_PLAYER_HURT);
		y += vy;
		health -= amount;
		animation = 1;
		animationclearframes = 20;
		if (health <= 0)
		{
			std::string message;

			if (isWifi() && isHost() == false)
			{
				unsigned short buffer[10];
				int client_id = getClientID();
				sprintf((char *) buffer, "%d", client_id);
				message = (char*) buffer;
			}
			else if (isWifi())
				message = "The host";
			else
				message = "Steve";
			if (type == CACTUS_HURT) message += " was pricked to death";
			else if (type == VOID_HURT) message += " fell out of the world";
			else if (type == PLAYER_HURT) message += " was killed by a player";
			else if (type == ZOMBIE_HURT) message += " was eaten by a zombie";
			else if (type == HEROBRINE_HURT) message += " was murdered by a Herobrine";
			else message += " died";
			message += "\n";
			print_message((char*) message.c_str());
		}
	}
}

void showHealth(int health)
{
	int i;
	for (i = 44; i < (health + 44) - 1; i += 2)
		showGraphic(&hearts[0], i * 4, 56);
	if (health % 2)
		showGraphic(&hearts[1], i * 4, 56);
}

void playerMob::updateMob(worldObject* world)
{
	if (host)
	{
		if (health > 0)
		{
			//Draw the inventory if the player is not dead, and it is survival mode
			if (isSurvival()) drawInv();
			++tillBrightness;
			if (tillBrightness > 60)
			{
				tillBrightness = 0;
				updateBrightnessAround(world, x / 16, y / 16);
			}
			++reheal;
			ping = 0;
			world->CamX = x - 256 / 2;
			world->CamY = y - 192 / 2;
			if (world->CamX < 0) world->CamX = 0;
			if (world->CamY < 0) world->CamY = 0;
			if (world->CamX > WORLD_WIDTH * 16 - 256) world->CamX = WORLD_WIDTH * 16 - 256;
			if (world->CamY > (WORLD_HEIGHT + 1)*16 - 192) world->CamY = (WORLD_HEIGHT + 1)*16 - 192;

			if (keysHeld() & getGlobalSettings()->getKey(ACTION_MOVE_RIGHT) && !collisions[1] && !collisions[3])
			{
				animateMob(&playerMobGraphic[0], 0);
				x += (isSurvival() || !getGlobalSettings()->getProperty(PROPERTY_SPEED)) ? 1 : 2;
				facing = false;
			}
			else if (keysHeld() & getGlobalSettings()->getKey(ACTION_MOVE_LEFT) && !collisions[2] && !collisions[3])
			{
				animateMob(&playerMobGraphic[0], 0);
				x -= (isSurvival() || !getGlobalSettings()->getProperty(PROPERTY_SPEED)) ? 1 : 2;
				facing = true;
			}
			else
				setAnimFrame(&playerMobGraphic[0], 0, 0);
			if (collisions[3] == true && world->blocks[x / 16][y / 16] != LADDER)
			{
				vy = 0;
				y += 1;
			}
			if (!(keysHeld() & getGlobalSettings()->getKey(ACTION_CLIMB)) && (world->blocks[x / 16][y / 16] == LADDER || world->blocks[x / 16][(y / 16) + 1] == LADDER || world->blocks[x / 16][(y / 16) + 2] == LADDER) && collisions[0] == false)
			{
				++slow;
				if (slow == 2)
				{
					vy = 1;
					++y;
					slow = 0;
				}
			}
			if (collisions[0] == false && (world->blocks[x / 16][y / 16] != LADDER && world->blocks[x / 16][(y / 16) + 1] != LADDER && world->blocks[x / 16][(y / 16) + 2] != LADDER))
				y += vy;
			else vy = 0;
			if ((keysDown() & getGlobalSettings()->getKey(ACTION_CLIMB) || keysDown() & getGlobalSettings()->getKey(ACTION_JUMP)) && (collisions[0] == true || !isSurvival()) && !collisions[3]) vy = (isSurvival() || !getGlobalSettings()->getProperty(PROPERTY_SPEED)) ? -2 : -3;
			y += vy;
			if (keysHeld() & getGlobalSettings()->getKey(ACTION_CLIMB) && (world->blocks[x / 16][y / 16] == LADDER || world->blocks[x / 16][(y / 16) + 1] == LADDER || world->blocks[x / 16][(y / 16) + 2] == LADDER) && !collisions[0] && !collisions[3]) y += -1;
			if (y > WORLD_HEIGHTPX) hurt(3, VOID_HURT);
			if (animationclearframes == 0) animation = 0;
			else --animationclearframes;
			if (reheal > 300)
			{
				if (health < 20)
					++health;
				reheal = 0;
			}
			showHealth(health);
		}
		else if (deathscreen == false)
		{
			clearInventory();
			deathScreenSetup();
			deathscreen = true;
			health = -50;
		}
		else
		{
			x = 1024;
			y = 1024;
			int result = deathScreenUpdate();
			if (result == 0)
			{
				int i, j;
				for (i = 0; i <= WORLD_WIDTH; i++)
					for (j = 0; j <= WORLD_HEIGHT; j++)
					{
						if (canPlayerMobSpawnHere(world, i, j))
						{
							x = i * 16;
							y = j * 16 - 16;
							deathscreen = false;
							health = PLAYER_FULL_HEALTH;
							i = WORLD_WIDTH + 1;
							j = WORLD_HEIGHT + 1;
							animation = 0;
						}
					}
			}
			else if (result == 1)
				quitGame = true;


		}
	}
	if (x - world->CamX>-16 && x - world->CamX < 256 + 16 && y - world->CamY>-32 && y - world->CamY < 256)
	{
		if (animation == 0)
			if (keysHeld() & KEY_TOUCH)
			{
				if (getTime() % 3 == 1)
					animateMob(&playerMobGraphic[PLAYER_SPRITE_MINE], 0);
				showGraphic(&playerMobGraphic[PLAYER_SPRITE_MINE], x - world->CamX - 5, y - world->CamY, facing ? true : false);
			}
			else
				showGraphic(&playerMobGraphic[PLAYER_SPRITE_WALK], x - world->CamX - 5, y - world->CamY, facing ? true : false);
		else if (animation == 1) showGraphic(&playerMobGraphic[PLAYER_SPRITE_HURT], x - world->CamX - 5, y - world->CamY, facing ? true : false);
	}
}

void playerMob::sendWifiUpdate()
{
}

void playerMob::saveToFile(FILE* pFile)
{
}

void playerMob::loadFromFile(FILE* pFile)
{
}

bool playerMob::isMyPlayer()
{
	return true;
}

bool canPlayerMobSpawnHere(worldObject* world, int x, int y)
{
	++y;
	if (!isBlockWalkThrough(world->blocks[x][y + 1]) && isBlockWalkThrough(world->blocks[x][y]) && world->blocks[x][y] != CACTUS && world->blocks[x][y + 1] != CACTUS) return true;
	return false;
}

void playerMobInit()
{
	loadGraphicAnim(&playerMobGraphic[PLAYER_SPRITE_WALK], 0); //Walk Animation
	loadGraphic(&playerMobGraphic[PLAYER_SPRITE_HURT], true, 1); //Hurt Graphic
	loadGraphicAnim(&playerMobGraphic[PLAYER_SPRITE_MINE], 2); //Mine Animation
	loadGraphicSub(&hearts[0], 0, 0);
	loadGraphicSub(&hearts[1], 0, 1);
}

