#include "world.h"
#include <nds.h>
#define NUM_BLOCKS 99
int getSelectedblock();
void miningUpdate(worldObject* world,int sx,int sy,touchPosition touch, int keys);
void blocksCanPlace();
void miningSetScene(bool a);
void setSelectedBlock(int a);