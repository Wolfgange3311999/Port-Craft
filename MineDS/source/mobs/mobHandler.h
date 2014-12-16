#include "../world.h"
#include "baseMob.h"
#include <fat.h>
int getDefaultSpawnX();
void savePlayer(FILE *data);
void loadPlayer(FILE *data);
void mobHandlerInit();
void mobHandlerUpdate(worldObject* world);
void mobHandlerKillMob(int a);
void mobHandlerReadWifiUpdate(int x,int y,int animation,int mobtype,int mobNum,worldObject* world,bool f);
void mobsReset();
void mobHandlerHurtMob(int mobNum,int amount, int type);
int isMobAt(int x,int y);
void mobHandlerHurtMobWifi(int mobNum,int amount, int type);
baseMob* mobHandlerFindMob(int range,int type,int x,int y);
