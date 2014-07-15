//A block has Two Functions
void GRAVEL_render(int a, int b,int c,int d,worldObject* e); //Render the block
void GRAVEL_setup(); //And copy the blocks graphics
#include "../player.h"
#include "../world.h"
void GRAVEL_colision(playerActor* player,worldObject* world,int bx,int by,int result);
void GRAVEL_mine(worldObject* world,int* mine_time,int x,int y);
void GRAVEL_render_nofall(int x,int y);
void GRAVEL_update(int bx,int by,worldObject* world,playerActor* player);