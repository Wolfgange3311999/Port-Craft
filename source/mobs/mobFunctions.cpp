#include <nds.h>
#include <stdio.h>
#include "BaseMob.h"
#include "../collision.h"
#include "../blocks.h"
#include "mobCollisions.h"
#include "../general.h"
#include "mobFunctions.h"
#include "hurt.h"
#include "../blockUpdaters/water.h"

void calculatePhysics(BaseMob *mob, bool inWater)
{
	if (mob->collisions[SIDE_BOTTOM] && mob->vy > 0)
	{
		if (int(mob->vy) > 9)
			mob->hurt(2 * (mob->vy - 9), FALL_HURT);
		mob->vy = 0;
	}
	else if (mob->collisions[SIDE_TOP] && mob->vy < 0)
		mob->vy = 0;
	else
		mob->vy += FixedPoint(true, (18 * FixedPoint::SCALER) / FPS); //Gravity Acceleration = +18.0 m/s^2

	//Velocity Cap
	if (mob->vy > (inWater ? 2 : 25)) mob->vy = inWater ? 2 : 25;
}

int blockAtPixel(WorldObject *world, int pixX, int pixY)
{
	return world->blocks[pixX / 16][pixY / 16];
}

void calculateCollisions(WorldObject *world, BaseMob *mob)
{
	mob->collisions[SIDE_BOTTOM] = !isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y + mob->sy / 2) / 16])
			|| !isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y + mob->sy / 2) / 16]);
	mob->collisions[SIDE_RIGHT] = !isBlockWalkThrough(world->blocks[int((mob->x + mob->sx / 2 + 1) / 16)][int((mob->y - mob->sy / 2 + 1) / 16)])
			|| !isBlockWalkThrough(world->blocks[int((mob->x + mob->sx / 2 + 1) / 16)][int((mob->y) / 16)])
			|| !isBlockWalkThrough(world->blocks[int((mob->x + mob->sx / 2 + 1) / 16)][int((mob->y + mob->sy / 2 - 1) / 16)]);
	mob->collisions[SIDE_LEFT] = !isBlockWalkThrough(world->blocks[int((mob->x - mob->sx / 2) / 16)][int((mob->y - mob->sy / 2 + 1) / 16)])
			|| !isBlockWalkThrough(world->blocks[int((mob->x - mob->sx / 2) / 16)][int((mob->y) / 16)])
			|| !isBlockWalkThrough(world->blocks[int((mob->x - mob->sx / 2) / 16)][int((mob->y + mob->sy / 2 - 1) / 16)]);
	mob->collisions[SIDE_TOP] = !isBlockWalkThrough(world->blocks[int((mob->x - mob->sx / 2 + 1) / 16)][int((mob->y - mob->sy / 2) / 16)])
			|| !isBlockWalkThrough(world->blocks[int((mob->x + mob->sx / 2) / 16)][int((mob->y - mob->sy / 2) / 16)]);
	mob->collisions[COLLISION_STUCK] = false;
}

void calculateMiscData(WorldObject *world, BaseMob *mob)
{
	if (mob->host)
	{
		calculatePhysics(mob, isWaterAt(world, mob->x + mob->sx - 1, mob->y) || isWaterAt(world, mob->x - mob->sx + 1, mob->y));
		for (int b = -1; b <= 1; ++b)
			cactusCheck(world, mob, 0, (mob->x) / 16, (mob->y) / 16 + b, false);

		bool inBlock = false;

		for (int x = mob->x - mob->sx / 2 + 1; x < mob->x + mob->sx / 2 + 1; x += mob->sx - 1)
		{
			for (int y = mob->y - mob->sy / 2 + 1; y < mob->y + mob->sy / 2; y += mob->sy / 2 - 1)
			{
				if (!isBlockWalkThrough(world->blocks[x / 16][y / 16]))
				{
					inBlock = true;
					break;
				}
			}
			if (inBlock)
				break;
		}

		if (inBlock)
		{ //move player out of block
			if (int(mob->y) % 16 < 3)
				mob->y -= int(mob->y) % 16;
			if ((!isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y) / 16])
					&& isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y) / 16]))
					||
					(!isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y - mob->sy / 2 + 1) / 16])
					&& isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y - mob->sy / 2 + 1) / 16]))
					||
					(!isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y + mob->sy / 2 - 1) / 16])
					&& isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y + mob->sy / 2 - 1) / 16])))
				mob->x -= int(mob->x + mob->sx / 2) % 16 + 1;
			else if ((!isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y) / 16])
					&& isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y) / 16]))
					||
					(!isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y - mob->sy / 2 + 1) / 16])
					&& isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y - mob->sy / 2 + 1) / 16]))
					||
					(!isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y + mob->sy / 2 - 1) / 16])
					&& isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y + mob->sy / 2 - 1) / 16])))
				mob->x += 16 - int(mob->x - mob->sx / 2 + 1) % 16;
			else if (int(mob->y) % 16 < 9)
				mob->y -= int(mob->y) % 16;
		}

		calculateCollisions(world, mob);
		if ((!mob->collisions[SIDE_BOTTOM] && mob->vy > 0) || (!mob->collisions[SIDE_TOP] && mob->vy < 0))
			mob->y += (16 * mob->vy) / FPS; //Main statement Positive velocity=down
		if ((mob->vx > 0 && !mob->collisions[SIDE_RIGHT]) || (mob->vx < 0 && !mob->collisions[SIDE_LEFT]))
			mob->x += (16 * mob->vx) / FPS;
		if (mob->x < mob->sx / 2) mob->x = mob->sx / 2;
		if (mob->y < mob->sy / 2) mob->y = mob->sy / 2;
		if (mob->x > WORLD_WIDTHPX - mob->sx / 2) mob->x = WORLD_WIDTHPX - mob->sx / 2;
	}
}

void calculateMiscDataSmall(WorldObject* world, BaseMob *mob)
{
	if (mob->host)
	{
		if (mob->x < 1) mob->x = 1;
		if (mob->y < 1) mob->y = 1;
		calculatePhysics(mob, isWaterAt(world, mob->x + mob->sx - 1, mob->y) || isWaterAt(world, mob->x - mob->sx + 1, mob->y));
		for (int b = -1; b <= 1; ++b)
			cactusCheck(world, mob, 0, (mob->x) / 16, (mob->y) / 16 + b, false);

		bool inBlock = false;

		for (int x = mob->x - mob->sx / 2 + 1; x < mob->x + mob->sx / 2 + 1; x += mob->sx - 1)
		{
			for (int y = mob->y - mob->sy / 2 + 1; y < mob->y + mob->sy / 2; y += mob->sy - 1)
			{
				if (!isBlockWalkThrough(world->blocks[x / 16][y / 16]))
				{
					inBlock = true;
					break;
				}
			}
			if (inBlock)
				break;
		}

		if (inBlock)
		{ //move player out of block
			if (int(mob->y) % 16 < 3)
				mob->y -= int(mob->y) % 16;
			if ((!isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y) / 16])
					&& isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y) / 16]))
					||
					(!isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y + mob->sy / 2 - 1) / 16])
					&& isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y + mob->sy / 2 - 1) / 16])))
				mob->x -= int(mob->x + mob->sx / 2) % 16 + 1;
			else if ((!isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y) / 16])
					&& isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y) / 16]))
					||
					(!isBlockWalkThrough(world->blocks[int(mob->x - mob->sx / 2 + 1) / 16][int(mob->y + mob->sy / 2 - 1) / 16])
					&& isBlockWalkThrough(world->blocks[int(mob->x + mob->sx / 2) / 16][int(mob->y + mob->sy / 2 - 1) / 16])))
				mob->x += 16 - int(mob->x - mob->sx / 2 + 1) % 16;
			else if (int(mob->y + mob->sy / 2) % 16 < 9)
				mob->y -= int(mob->y + mob->sy / 2) % 16;
		}

		calculateCollisions(world, mob);
		if ((!mob->collisions[SIDE_BOTTOM] && mob->vy > 0) || (!mob->collisions[SIDE_TOP] && mob->vy < 0))
			mob->y += (16 * mob->vy) / FPS; //Main statement Positive velocity=down
		if ((mob->vx > 0 && !mob->collisions[SIDE_RIGHT]) || (mob->vx < 0 && !mob->collisions[SIDE_LEFT]))
			mob->x += (16 * mob->vx) / FPS;
	}
}

bool onScreen(int x, int y, int camX, int camY)
{
	return x > camX && x < camX + 256 && y > camY && y < camY + 192;
}

