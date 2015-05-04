#include <stdio.h>
#include "../world.h"
#include "baseMob.h"
#ifndef COW_MOB_H
#define COW_MOB_H
bool canCowMobSpawnHere(WorldObject* world, int x, int y);

class cowMob : public baseMob {
public:
	int jump;
	bool scared = false; //Whether cow is scared and will run away from the player
	int scaredtimer; //Limits how long the cow is scared
	bool dir; //Direction of cow movement
	int mov; //Loop counter for cow movement
	baseMob* target;
	int notarget;
	virtual void saveToFile(FILE* sFile);
	virtual void loadFromFile(FILE* sFile);
	virtual void sendWifiUpdate();
	virtual void updateMob(WorldObject* world);
	virtual void hurt(int amount, int type);
	virtual bool isMyPlayer();
	cowMob();
	cowMob(int x, int y);

	~cowMob() {
	}
};
void cowMobInit();
#endif
