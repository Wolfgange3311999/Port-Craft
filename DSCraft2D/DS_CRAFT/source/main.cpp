//The main.cpp is the simplist file of all, and it should be
//BUT it depends on many other files that are more complex
#include <nds.h>
#include "ndsvideo.h" // Include the video functions (for setupVideo();)
#include "player.h" // The player fuctions
#include "sprcount.h" //The sprite number counter
#include "world.h" //A World!!!!!
#include "worldgen.h"
#include <stdio.h> //For Rand
#include <time.h>
#include "blockID.h" //The Block ID numbers to a word
int main(){
	setupVideo(); //Setup all the video we need (in ndsvideo.h/cpp)
	lcdMainOnBottom();
	playerActor MainPlayer; //Create a Player Object
	worldObject CurrentWorld;
	srand(time(NULL)); //The seed :)
	consoleDemoInit();
	generateWorld(&CurrentWorld);
	CurrentWorld.CamX=0; //Testing stuff
	CurrentWorld.CamY=0;
	MainPlayer.x=CurrentWorld.CamX+128-16;//Place the player in the middle of the screen
	MainPlayer.y=CurrentWorld.CamY+96-32;
	worldSetUp();
	touchPosition touch;
	while(1){
		scanKeys();
		if (keysHeld() & KEY_TOUCH){
			touchRead(&touch);
			int lax=touch.px/32;
			int lay=touch.py/32;
			lax+=CurrentWorld.CamX/32;
			lay+=CurrentWorld.CamY/32;
			CurrentWorld.blocks[lax][lay]=8123;
		}
		fixgrass(&CurrentWorld);
		consoleClear();
		updateplayer(&MainPlayer,&CurrentWorld);	//Update the player
		worldUpdate(&CurrentWorld);
		iprintf("Camera Position:%d,%d\n",CurrentWorld.CamX,CurrentWorld.CamY);
		iprintf("Player Position:%d,%d\n",MainPlayer.x,MainPlayer.y);
		iprintf("Player BlockPos:%d,%d\n",MainPlayer.blockx,MainPlayer.blocky);
		iprintf("Sprites on Screen: %d\n",nextSprite());
		swiWaitForVBlank(); //Wait for a VBlank
		oamUpdate(&oamMain); //Update the sprites
		resetSpriteCount(); //And set the sprite number counter to 0

	}
}
