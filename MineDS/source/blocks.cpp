/*
        ----------------------------------------
        |                                       |
        |               Blocks.cpp              |
        |        General Block Handling         |
        -----------------------------------------
*/
#include "blockID.h"
#define sizeOfArray(x) (sizeof(x)/4)
int walkThroughBlocks[]={LOG,OAK_WOOD,BIRCH_WOOD,LEAF,YELLOW_FLOWER,RED_FLOWER,AIR,CACTUS,TORCH,SNOW_TOP,REDWOOD_LEAF,SNOW};
int lightSourceBlocks[]={TORCH,PUMPKIN_LIGHT};
int sourceAmount[]={1,0};
int isBlockWalkThrough(int blockID)
{
        int i;
        bool isWalkThrough=false;
        for(i=0;i<=sizeOfArray(walkThroughBlocks);i++)
        {
                if (walkThroughBlocks[i]==blockID) isWalkThrough=true;
        }
        return isWalkThrough;
}
int isAGroundBlock(int blockID)
{
        return false;
}
bool isBlockALightSource(int blockID)
{
	int i;
        bool isLightSource=false;
        for(i=0;i<=sizeOfArray(lightSourceBlocks);i++)
        {
                if (lightSourceBlocks[i]==blockID) isLightSource=true;
        }
        return isLightSource;
}
int getLightAmount(int blockID)
{
	int i;
        bool isLightSource=false;
        for(i=0;i<=sizeOfArray(lightSourceBlocks);i++)
        {
                if (lightSourceBlocks[i]==blockID) return sourceAmount[i];
        }
}
