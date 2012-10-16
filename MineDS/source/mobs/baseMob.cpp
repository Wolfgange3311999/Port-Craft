#include <stdio.h>
#include "../world.h"
#include "../blocks.h"
#include "../graphics/graphics.h"
#include "../debugflag.h"
#include "baseMob.h"
#include "../blockID.h"
//ASDF?
Graphic baseMobGraphic[3];
baseMob::baseMob()
{
	x=0;
	y=0;
	vy=0;
	vx=0;
	alive=false;
	onground=false;
	health=10;
	mobtype=0;
}
baseMob::baseMob(int a,int b)
{
	gravity=8;
	gravityValue=8;
	sx=16;
	sy=32;
	x=a;
	y=b;
	vy=0;
	vx=0;
	onground=false;
	alive=false;
	mobtype=0;
	health=10;
}
void baseMob::resetVelocity()
{
	vy=0;
	vx=0;
}
void baseMob::updateMob(worldObject* world)
{
	 showGraphic(&baseMobGraphic[0],x-world->CamX,y-world->CamY);
	if (host==true)
	{
		if (health<=0)
		{
			killMob();
		}
		if (colisions[0]==false) y+=vy;
		else vy=0;
		//iprintf("colisions = %d\n",colisions[0]);
	}
}
void baseMob::setXYPos(int a,int b)
{
	x=a;
	y=b;
}
void baseMob::sendWifiUpdate()
{
}
void baseMob::saveToFile(FILE* pFile)
{
}
void baseMob::loadFromFile(FILE* pFile)
{
}
bool canBaseMobSpawnHere(worldObject* world,int x,int y)
{
	y++;
	if (!isBlockWalkThrough(world->blocks[x][y+1]) && isBlockWalkThrough(world->blocks[x][y]) && world->blocks[x][y]!=CACTUS) return true;
	return false;
}
void baseMobInit()
{
	loadGraphic(&baseMobGraphic[0],true,0);
}
void baseMob::hurt(int amount,int type)
{
	health-=amount;
}
void baseMob::killMob()
{
	alive=false;
}
void baseMob::unKillMob()
{
	alive=true;
}
