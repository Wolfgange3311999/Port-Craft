#pragma once
#include <stdio.h>
#include "../world/WorldObject.h"
#include "BaseMob.h"
#define ZOMBIE_SPEED 0.5

bool canZombieMobSpawnHere(WorldObject &world, int x, int y);

class ZombieMob : public BaseMob
{
public:
	void calcMiscData(WorldObject &world);
	void saveToFile(FILE* sFile);
	void loadFromFile(FILE* sFile);
	void sendWifiUpdate();
	void updateMob(WorldObject &world);
	void hurt(int amount, int type);
	bool isMyPlayer();

	ZombieMob(int x, int y) : BaseMob(MOB_ZOMBIE, x, y, 6, 32, GRAPHIC_MOB, 3, 16, 32) { }

	~ZombieMob() { }
};