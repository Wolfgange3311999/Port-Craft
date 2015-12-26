#pragma once
#include <stdio.h>
#include <memory>
#include "../world/WorldObject.h"
#include "../graphics/graphics.h"
#include "../FixedPoint.h"

#define SIDE_BOTTOM 0
#define SIDE_RIGHT 1
#define SIDE_LEFT 2
#define SIDE_TOP 3
#define COLLISION_STUCK 4

enum MobType
{
	MOB_ANIMAL = 0,
	MOB_HEROBRINE = 1,
	MOB_ITEM = 2,
	MOB_MULTIPLAYER = 3,
	MOB_PLAYER = 4,
	MOB_ZOMBIE = 5,
	MOB_WATER = 6
};

bool canBaseMobSpawnHere(WorldObject &world, int x, int y);

class BaseMob
{
private:

	virtual int getMaxHealth()
	{
		return 10;
	}
protected:
	Graphic normalSprite, hurtSprite;

	BaseMob(MobType type, int x, int y, int sx, int sy, GraphicType gType, int frame, int gsx, int gsy, int pID = 10) :
	normalSprite(gType, frame, gsx, gsy, pID), hurtSprite(gType, frame + 1, gsx, gsy, pID), type(type), health(256), x(x),
	y(y), vx(0), vy(0), sx(sx), sy(sy), smallMob(false),
	alive(true), onCactus(false), facing(true), collisions { }

	,
	spriteState(0), framesHurtSprite(0),
	timeOnCactus(30), framesFarAway(0), brightness(-1), host(true), isInWater(false) { }

	void calcMobBrightness(WorldObject &world)
	{
		hurtSprite.paletteID = normalSprite.paletteID = 8 + (6 * (brightness = world.brightness[x / 16][y / 16 + 1])) / 15;
	}
public:
	MobType type;
	int health; //0 = Dead
	FixedPoint x, y, vx, vy;
	int sx, sy;
	bool smallMob, alive, onCactus, facing, collisions[5];
	int spriteState, framesHurtSprite, timeOnCactus, framesFarAway, brightness;

	//Multiplayer
	bool host;
	bool isInWater;

	virtual void updateMob(WorldObject &world) = 0;
	virtual void calcMiscData(WorldObject &world) = 0;

	virtual void saveToFile(FILE* sFile) { }

	virtual void loadFromFile(FILE* sFile)
	{
		health = 0;
	}
	virtual void hurt(int amount, int type);
	virtual void calcHealth();
	virtual bool isMyPlayer();
	bool canJump(WorldObject *world = nullptr);
	bool isInBlock(WorldObject &world);

	BaseMob(MobType type, int x, int y, int sx, int sy) :
	normalSprite(), hurtSprite(), type(type), health(256), x(x),
	y(y), vx(0), vy(0), sx(sx), sy(sy), smallMob(false),
	alive(true), onCactus(false), facing(true), collisions { }
	, spriteState(0), framesHurtSprite(0),
	timeOnCactus(30), framesFarAway(0), brightness(-1), host(true), isInWater(false) { }

	virtual ~BaseMob()
	{
	}
};
using BaseMob_ptr = std::shared_ptr<BaseMob>;
bool jumpHurtType(int hurtType);