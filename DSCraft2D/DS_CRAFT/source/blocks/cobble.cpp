#include <nds.h> //BLAH
#include "../ndsvideo.h"
#include "block.h" //Include the block graphics
#include "../blockID.h"
#include "../world.h"
#include "../player.h"
#include "../sounds.h"
#include "../inventory.h"
u16* COBBLEgfx;
int cobblels;
void COBBLE_render(int x,int y){
	createsprite32x32(x,y,COBBLEgfx,false,0);	
}
void COBBLE_setup(){
	COBBLEgfx=oamAllocateGfx(&oamMain,SpriteSize_32x32,SpriteColorFormat_256Color);
	char* blocktiles;
	blocktiles=(char*)&blockTiles;
	blocktiles+=(32*32)*COBBLE;
	dmaCopy(blocktiles,COBBLEgfx,32*32);
}
void COBBLE_colision(playerActor* player,worldObject* world,int bx,int by,int result){
	if (result==0 || result==2){
		player->y=by*32-63; //64 == playerheight
		player->vy=0;
		player->onblock=true;
		if (!(bx==player->sx && by==player->sy)){
			player->sx=bx,player->sy=by;
			if (cobblels==0){
				playSound(STONE_A);		
				cobblels++;
			}
			else if (cobblels==1){
				playSound(STONE_B);
				cobblels++;
			}	
			else if (cobblels==2){
				playSound(STONE_C);
				cobblels++;
			}			
			else if (cobblels==3){
				playSound(STONE_D);
				cobblels=0;
			}
		}	
	}
	if (result==3){//player colides on right
		player->x-=2; //Move him back one so he is not coliding anymore :)
	}
	if (result==1){//colides on left
		player->x+=2;
	}
	if (result==4){
		//colision upwards
		player->vy=0;
		player->y=by*32+33;
	}
}
void COBBLE_mine(worldObject* world,int* mine_time,int x,int y){
	if (*mine_time>600 && world->ChoosedBlock!= WOOD_PICK && world->ChoosedBlock!=COBBLE_PICKAXE && world->ChoosedBlock!=IRON_PICKAXE && world->ChoosedBlock==AIR){
		world->blocks[x][y]=AIR;
		*mine_time=0;
	}
	else if(*mine_time>600 && world->ChoosedBlock!= WOOD_PICK && world->ChoosedBlock!=IRON_PICKAXE && world->ChoosedBlock!=COBBLE_PICKAXE && world->ChoosedBlock!=AIR){
		world->blocks[x][y]=AIR;
		*mine_time=0;
		setData(world->ChoosedBlock,2,true); //Add 1 "use" to the pickaxe...
	}
	else if (*mine_time>90 && world->ChoosedBlock==WOOD_PICK){
		world->blocks[x][y]=AIR;
		inventoryAdd(COBBLE);
		setData(WOOD_PICK,1,true); //Add 1 "use" to the pickaxe...
		*mine_time=0;
	}
	else if (*mine_time>45 && world->ChoosedBlock== COBBLE_PICKAXE){
		world->blocks[x][y]=AIR;
		inventoryAdd(COBBLE);
		setData(COBBLE_PICKAXE,1,true); //Add 1 "use" to the pickaxe...
		*mine_time=0;
	}	
	else if (*mine_time>45 && world->ChoosedBlock== IRON_PICKAXE){
		world->blocks[x][y]=AIR;
		inventoryAdd(COBBLE);
		setData(IRON_PICKAXE,1,true); //Add 1 "use" to the pickaxe...
		*mine_time=0;
	}
}