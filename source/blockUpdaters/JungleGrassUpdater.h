#pragma once
#include "../WorldObject.h"
#include "blockUpdater.h"

class JungleGrassUpdater : public BlockUpdater
{
public:
	JungleGrassUpdater();
	virtual void chanceUpdate(WorldObject &world, int x, int y, bool bg);
};

