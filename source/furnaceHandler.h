#pragma once
#include "world/World.h"

void convertItemToFuel(Furnace &furnace);
void createFurnace(World &world, int x, int y, bool bg);
void destroyFurnace(World &world, int x, int y, bool bg);
void openFurnace(World &world, int x, int y, bool bg);
void closeFurnace();
int getOpenedFurnaceID();
void createResult(Furnace &furnace);
int fuelNeeded(const Furnace &furnace);
void saveFurnaces(FILE *file, World &world);
void loadFurnaces(FILE *file, World &world);

inline int getFurnaceID(World &world, int x, int y, bool bg)
{
	return (world.data[x][y] & (bg ? 0x000F0000 : 0x0000000F)) >> (bg ? 4 * 4 : 0);
}