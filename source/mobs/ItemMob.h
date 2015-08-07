#pragma once
#include "BaseMob.h"
#include <cstdlib>
#include "../graphics/graphics.h"

class ItemMob : public BaseMob
{
private:
	static const int floatVal[];
public:
	int blockID;
	int displayID;
	int amount;
	int floatY;

	void calcMiscData(WorldObject* world);
	void saveToFile(FILE* sFile);
	void loadFromFile(FILE* sFile);
	void sendWifiUpdate();
	void updateMob(WorldObject* world);
	void hurt(int amount, int type);
	bool isMyPlayer();

	ItemMob(int x, int y, int blockID, int amount, int displayID, float vx) :
	BaseMob(MOB_ITEM, x, y, 8, 8), blockID(blockID), displayID(displayID)
	, amount(amount), floatY(0)
	{
		if (vx == 54321.f)
			this->vx = FixedPoint(true, (float((rand() % 10) + 40) / 100.f) * ((rand() % 2) ? -1.f : 1.f) * FixedPoint::SCALER);
		else
			this->vx = FixedPoint(true, vx * 10);
	}

	~ItemMob() { }
};
