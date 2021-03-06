#include "../world/World.h"
#include "../general.h"
#include "../graphics/graphics.h"
#include "blockUpdater.h"
#include <stdlib.h>
#include "../blockID.h"
#include "FurnaceUpdater.h"
#include "../furnaceHandler.h"

FurnaceUpdater::FurnaceUpdater()
{
	chance = NO_CHANCE;
}

bool FurnaceUpdater::update(World &world, int x, int y, bool bg)
{
	if (world.furnaces[getFurnaceID(world, x, y, bg)].fuelAmount > 0)
	{
		if (bg)
			world.bgblocks[x][y] = FURNACE_LIT;
		else
			world.blocks[x][y] = FURNACE_LIT;
	}
	updateSingleBlock(world, x, y, bg, FPS);
	return false;
}