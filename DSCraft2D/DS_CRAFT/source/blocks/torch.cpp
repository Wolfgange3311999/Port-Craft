#include <nds.h>
#include "../ndsvideo.h"
#include "block.h"
#include "../player.h"
#include "../world.h"
#include "../blockID.h"
u16* TORCHgfx;
void TORCH_render(int x,int y){
	createsprite32x32(x,y,TORCHgfx,false,0);	
}
void TORCH_setup(){
	TORCHgfx=oamAllocateGfx(&oamMain,SpriteSize_32x32,SpriteColorFormat_256Color);
	char* blocktiles;
	blocktiles=(char*)&blockTiles;
	blocktiles+=(32*32)*TORCH;
	dmaCopy(blocktiles,TORCHgfx,32*32);
}
void TORCH_update(int bx,int by,worldObject* world,playerActor* player){
	if (world->blocks[bx][by+1]==AIR) world->blocks[bx][by]=AIR;
	else if (world->blocks[bx][by+1]==TORCH) world->blocks[bx][by]=AIR;
}
