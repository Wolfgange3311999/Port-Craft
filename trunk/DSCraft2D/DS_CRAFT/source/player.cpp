#include "ndsvideo.h" // Include the DS video stuff
#include <stdio.h>
#include <nds.h> //Include the DS library (for u16*)
#include "player.h" //Include the player structure
#include "PlayerR.h" //Include the player graphics
#include "world.h" //A world!!!
#include "allblocks.h"
#include "gameshelper.h"
#include "blockID.h"
#define INSIDE 0
#define LEFT 1
#define UNDER 2
#define RIGHT 3
#define UP 4
#define U_L 5
#define U_R 6
u16* playerGraphics;
bool top;
#define gravity 1
int colisionAdv(int blockx1,int blocky1,int blockx2,int blocky2,int x1,int y1,int x2,int y2){
	if (spritecol(x1+8,y1,x2,y2,16,64,32,32)){
		//A good square colision
			if (blockx1==blockx2 && blocky1 == blocky2){
				return INSIDE;
			}
			if (blockx1==blockx2 && blocky1+1 == blocky2){
				top=true;
				return UNDER;
			}
			if (blockx1+1==blockx2 && blocky1 == blocky2){
				return RIGHT;
			}
			if (blockx1+1==blockx2 && blocky1-1 == blocky2){
				return RIGHT;
			}
			if (blockx1-1==blockx2 && blocky1 == blocky2){
				return LEFT;
			}
			if (blockx1-1==blockx2 && blocky1-1 == blocky2){
				return LEFT;
			}
			if (blockx1==blockx2 && blocky1-1 == blocky2){
				return UP;
			}
	}	
	return 7;
}
void playerGravity(playerActor* player,worldObject* world){
	//colisionAdv(player->blockx,player->blocky,i,j,player->x,player->y,i*32,j*32)
	printf("Gravity\n");
	int x,y;
	player->onblock=false;
	if (player->vy<12) player->vy+=gravity; //vy is speed
	for (x=0;x<=WORLD_WIDTH;x++)
		for(y=0;y<=WORLD_HEIGHT;y++){
			int result=colisionAdv(player->blockx,player->blocky,x,y,player->x,player->y,x*32,y*32);
			if (world->blocks[x][y]==GRASS) GRASS_colision(player,world,x,y,result);
			else if (world->blocks[x][y]==DIRT) DIRT_colision(player,world,x,y,result);
			else if (world->blocks[x][y]==BEDROCK) BEDROCK_colision(player,world,x,y,result);
		}
	if(player->onblock==false) player->y+=player->vy;
	if(keysHeld() & KEY_A && player->onblock==1)
	{
		player->vy=-11; // The -value is the rate which the guy jumps (DONT make it 1 hundred :P OR 1)
		player->y-=1;
	}
}
void updateplayer(playerActor* player,worldObject* world){
	//Scan the keys and move that minecraft guy, soon this will need the world values	
	scanKeys();
	if (keysHeld() & KEY_LEFT)player->x--;
	else if (keysHeld() & KEY_RIGHT) player->x++;
	world->CamX=player->x-(256/2-16);
	world->CamY=player->y-(192/2-32);
	//Create the block positions
	player->blockx=(player->x+15)/32;
	player->blocky=(player->y+32)/32;	
	//Stop at end of map
	if (world->CamX>world_widthpx-(256-32)) world->CamX=world_widthpx-(256-32);
	else if (world->CamX<0) world->CamX=0;
	if (world->CamY>world_heightpx-(192-32)) world->CamY=world_heightpx-(192-32);
	else if (world->CamY<0) world->CamY=0;
	if (player->x>world_widthpx) player->x=world_widthpx;
	else if (player->x<0)player->x=0;
	if (player->y>world_heightpx-32) player->y=world_heightpx-32;
	else if (player->y<0) player->y=0;
	playerGravity(player,world);
	createsprite32x64(player->x-world->CamX,player->y-world->CamY,playerGraphics,keysHeld() & KEY_LEFT,1);
}
u16* playerGfx(){
	return playerGraphics;
}
void playerCreateGfx(){
	//Copy the player graphics into memory
	//Called by setupVideo();
	playerGraphics=oamAllocateGfx(&oamMain,SpriteSize_32x64, SpriteColorFormat_256Color);
	dmaCopy(PlayerRTiles,playerGraphics,PlayerRTilesLen);
}
