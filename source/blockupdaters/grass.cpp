#include "../world.h"
#include "../general.h"
#include "../graphics/graphics.h"
#include "../blockupdate.h"
#include <stdlib.h>
#include "../blockID.h"
#include "../blocks.h"
#include "grass.h"
#include "../daynight.h"
#include "../worldRender.h"

grassUpdater::grassUpdater()
{
	blockID = GRASS;
	chance = SOIL_CHANCE_UPDATE;
}

void grassUpdater::chanceUpdate(WorldObject* world, int x, int y, bool bg)
{
	int &blockXY = bg ? world->bgblocks[x][y] : world->blocks[x][y];
	int &blockAboveXY = bg ? world->bgblocks[x][y - 1] : world->blocks[x][y - 1];
	if (!isBlockWalkThrough(blockAboveXY) || (getBrightness(world, x, y) >= 2 && isDay(world)))
		blockXY = DIRT;
	else if (world->biome[x] == BIOME_SNOW && !bg && rand() % 10 == 0 && blockAboveXY == AIR)
	{
		blockXY = SNOW_GRASS;
		blockAboveXY = SNOW_TOP;
	}
	else if (world->biome[x] == BIOME_SNOW && bg && rand() % 10 == 0 && world->blocks[x][y - 1] == SNOW_TOP)
		blockXY = SNOW_GRASS;
}