#include "../blocks.h"
#include "hurt.h"
#include "../graphics/graphics.h"
#include "herobrineMob.h"
#include "mobHandler.h"
#include "../blockID.h"
#include "../collision.h"
#include "../worldRender.h"
#include "../inventory.h"
#include "../mining.h"
//#include "../sounds.h"

Graphic herobrineMobGraphic[3];

herobrineMob::herobrineMob()
{
	x = 0;
	y = 0;
	vy = 0;
	vx = 0;
	ping = 0;
	alive = false;
	onground = false;
	health = 10;
	mobtype = 0;
	animationclearframes = 0;
	notarget = 0;
}

herobrineMob::herobrineMob(int a, int b)
{
	jump = 0;
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
	mobtype = 3;
	health = 20;
	ping = 0;
	animation = 0;
	notarget = 0;
	timeTillWifiUpdate = rand() % 4 + 4;
}

void herobrineMob::updateMob(worldObject* world)
{
	if (animation == 0) showGraphic(&herobrineMobGraphic[0], x - world->CamX - (facing ? 10 : 0), y - world->CamY, facing ? true : false);
	else if (animation == 1) showGraphic(&herobrineMobGraphic[1], x - world->CamX - (facing ? 10 : 0), y - world->CamY, facing ? true : false);
	if (host == true)
	{
		target = mobHandlerFindMob(128, 2, x, y);
		if (target->x < x && target->mobtype == 2) facing = true;
		else if (target->mobtype == 2) facing = false;
		jump++;
		if (collisions[0] == false) y += vy;
		else vy = 0;
		if (target->x > x - 4 && target->x < x + 4)
		{
			jump = 0;
		}
		if (target->mobtype != 2)
		{
			notarget++;
			jump = 0;
		}
		else if (!collisions[1] && facing == false && !collisions[3] && jump > 1)
		{
			x += facing ? -1 : 1;
			jump = 0;
		}
		else if (!collisions[2] && facing == true && !collisions[3] && jump > 1)
		{
			x += facing ? -1 : 1;
			jump = 0;
		}
		else if ((collisions[1] || collisions[2]) && collisions[0] && !collisions[3] && animation != 1)
		{
			vy = -2;
			y += vy;
		}
		if (target->mobtype == 2) notarget = 0;
		if (collisions[3])
		{
			vy = 0;
			y += 3;
		}
		ping = 0;
		if (notarget > 1800) killMob();
		if (animationclearframes == 0) animation = 0;
		else animationclearframes--;
		//iprintf("collisions = %d\n",collisions[0]);
		if (spritecol(x, y, target->x, target->y, sx, sy, target->sx, target->sy))
		{
			mobHandlerHurtMob(target->mobId, 1, HEROBRINE_HURT);
		}
		target = mobHandlerFindMob(512, 2, x, y);
		if (target->mobtype == 2) notarget = 0;
	}
}

void herobrineMob::sendWifiUpdate()
{
}

void herobrineMob::saveToFile(FILE* pFile)
{
}

void herobrineMob::loadFromFile(FILE* pFile)
{
}

bool canHerobrineMobSpawnHere(worldObject* world, int x, int y)
{
	y++;
	if (!isBlockWalkThrough(world->blocks[x][y + 1]) && isBlockWalkThrough(world->blocks[x][y]) && world->blocks[x][y] != CACTUS && world->blocks[x][y + 1] != CACTUS)
	{
		if (getBrightness(world, x, y + 1) > 7)
			return true;
	}
	return false;
}

void herobrineMobInit()
{
	loadGraphic(&herobrineMobGraphic[0], true, 8);
	loadGraphic(&herobrineMobGraphic[1], true, 9);
}

void herobrineMob::hurt(int amount, int type)
{

	if (animation == 1)
		return;
	if (type != VOID_HURT)
		vy -= 2;
	y += vy;
	//playSound(HEROBRINE_H);
	health -= amount;
	animation = 1;
	animationclearframes = 20;
	if (health <= 0)
	{
		if (type == PLAYER_HURT)
			addInventory(rand() % (NUM_BLOCKS - 2) + 2, rand() % 2 + 1);
		killMob();
	}
}

bool herobrineMob::isMyPlayer()
{
	return false;
}