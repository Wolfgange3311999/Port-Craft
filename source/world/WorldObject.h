#pragma once
#include <time.h>
#include <algorithm>
#include "../Furnace.h"
#include "../inventory.h"

#define WORLD_HEIGHT	(128)
#define WORLD_WIDTH	(1024)
#define WORLD_HEIGHTPX	(WORLD_HEIGHT * 16)
#define WORLD_WIDTHPX	(WORLD_WIDTH * 16)

#define CHEST_SLOTS 30
#define MAX_CHESTS 30
#define MAX_FURNACES 30
#define INDEX_BLOCK_ID 0
#define INDEX_AMOUNT 1

enum GameMode
{
	GAMEMODE_CREATIVE = 1,
	GAMEMODE_SURVIVAL = 2,
	GAMEMODE_PREVIEW = 3
};

enum Biome
{
	BIOME_PLAINS = 1,
	BIOME_SNOW = 2,
	BIOME_DESERT = 3,
	BIOME_JUNGLE = 4,
	BIOME_MUSHROOM = 5,
	BIOME_OCEAN = 6
};

class World
{
	static const int NO_SEED = 0;
	static int useSeed;

	void generateSmallWorld();
	void generate();
	void initialize();
public:
	short blocks[WORLD_WIDTH][WORLD_HEIGHT];
	short bgblocks[WORLD_WIDTH][WORLD_HEIGHT];
	int data[WORLD_WIDTH][WORLD_HEIGHT];
	short brightness[WORLD_WIDTH][WORLD_HEIGHT];

	int spawnX;
	int camY;
	int camX;
	int timeInWorld;
	int sunBrightness;
	GameMode gameMode;
	int seed; //The random number seed used to generate the world
	double camCalcX;
	double camCalcY;
	Biome biome[WORLD_WIDTH];
	bool chestInUse[MAX_CHESTS];
	Inventory chests[MAX_CHESTS];
	Furnace furnaces[MAX_FURNACES];
	int reservedWater;

	World(GameMode gameMode = GAMEMODE_PREVIEW);
	World(bool init);

	~World()
	{
	}
};

int findFirstBlock(World &world, int x);
int findFirstBiomeBlock(World &world, int x);
void drawLineDown(World &world, int x, int y);
void drawLineThing(World &world, int x1, int y1, int x2, int y2);
