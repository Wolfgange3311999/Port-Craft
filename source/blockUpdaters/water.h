#pragma once
#include "../world.h"
#include "../blockUpdater.h"

class WaterUpdater : public BlockUpdater
{
public:
	WaterUpdater();
	virtual void update(WorldObject* world, int x, int y, bool bg);
	void attemptSpreading(WorldObject* world, int x, int y);
	void attemptSharing(WorldObject* world, int x, int y);
};