/*
 * -----------------------------------------
 * |             Inventory.cpp             |
 * |           Inventory Funtions          |
 * -----------------------------------------
 */
#include <stdio.h>
#include "mining.h" //for NUM_BLOCKS
#include "graphics/graphics.h"
#include "graphics/inventoryGraphics.h"
#include "graphics/subBgHandler.h"
#include "titlescreen.h"
#include "crafting.h"
#include "inventory.h"
#include "blockID.h"
#include "blocks.h"
#include "general.h"
#include "titlescreen.h" // for isSurvival
#include <nds.h> // for keysDown()
#include <stdio.h> // for fileio
#include "controls.h"
#include "world.h"
#include "files.h"
bool loadedGraphic = false;
int selectedspace = -1;
Graphic heldBlock;
/*					A reminder:
 * INVENTORY STRUCT USES blockId, not blockID, for what ever reason!!!!!
 */


int showingInventory;
Inventory mainPlayerInv;
void saveInventory(FILE* data)
{
 fwrite(&mainPlayerInv,sizeof(mainPlayerInv),1,data);
}
void loadInventory(FILE* data)
{
 fread(&mainPlayerInv,sizeof(mainPlayerInv),1,data);
}
bool addInventory(int blockID, int amount) //adds the specified amount to a blockvalue
{
	//First find a spot availabe for the block id
	if (isSurvival()==false) //Always return true in creative!
		return true;
	
	int i;
	int space=-1;
	
	if (getType(blockID) == STONEBLOCK)
	{
		if (getType(getSelectedblock())!=PICKAXE)
			return true;
		else
		{
			switch (blockID)
			{
				case COAL_ORE: blockID = COAL; break; //Any pickaxe can break coal
				case STONE: blockID = COBBLESTONE; break;
				case IRON_ORE:if (getSelectedblock()==PICKAXE_WOOD) return true; break;
				case GOLD_ORE:if (getSelectedblock()==PICKAXE_WOOD || getSelectedblock()==PICKAXE_STONE)return true; break;
				case DIAMOND_ORE: if (getSelectedblock()!=PICKAXE_DIAMOND && getSelectedblock()!= PICKAXE_IRON) return true; break;
			}
		}
	}
	
	switch (blockID)
	{
		case GRASS: case JUNGLE_GRASS: case SNOW_GRASS: case MYCELIUM: blockID = DIRT; break;
		case TALL_GRASS: blockID = SEEDS_WHEAT; amount = rand()%2+1; break;
		case BEDROCK: return false; break; //Cannot break bedrock
		case SNOW_TOP: return true; break; //Can break snow tops, just they won't be added to the inventory
		case AIR: return false; break;
		case MUSHROOM_STEM: case MUSHROOM_TOP: return true; break;
	}
	
	for (i=0;i<NUM_INV_SPACES;i++)
	{
		//Found the correct block with correct id.
		if (mainPlayerInv.blocks[i].blockId==blockID)
		{
			space=i;
			i=NUM_INV_SPACES+1;
			//Skip other inventory spaces...
		}
		//Found a sutiable air space.
		else if (mainPlayerInv.blocks[i].blockId==AIR)
		{
			//Set the space as last resort, try to find correct inventory space.
			space=i;
		}
	}	
	if (space==-1)
	{
		show_message("No space for item");
		return false; //We still want the block to be broken - Do we ?
	}
	//Space now equals the block for the id...
	mainPlayerInv.blocks[space].blockId=blockID;
	mainPlayerInv.blocks[space].blockAmount+=amount;
	updateInvGraphics();
	return true;
}

void addInventory(int blockID)
{
	addInventory(blockID,1);
}

bool subInventory (int blockID, int amount) //subtracts the specified amount to a blockvalue
{
	if (isSurvival()==false) //Always return true in creative!
		return true;
	int i;
	int space=-1;
	for (i=0;i<NUM_INV_SPACES;i++)
	{
		//Found the correct block with correct id.
		if (mainPlayerInv.blocks[i].blockId==blockID)
		{
			space=i;
			i=NUM_INV_SPACES+1;
			//Skip other inventory spaces...
		}
	}	
	if (space==-1)
	{
		show_message("No item to remove\n");
		return false;
	}
	mainPlayerInv.blocks[space].blockAmount-=amount;
	if (mainPlayerInv.blocks[space].blockAmount<0)
	{
		mainPlayerInv.blocks[space].blockAmount+=amount;
		return false;
	}
	else if (mainPlayerInv.blocks[space].blockAmount==0)
	{
		mainPlayerInv.blocks[space].blockId=AIR;
	}
	updateInvGraphics();
	return true;
}

int checkInventory (int blockID) //returns quantity of blockid in inventory
{
	int i;
	int space=-1;
	for (i=0;i<NUM_INV_SPACES;i++)
	{
		//Found the correct block with correct id.
		if (mainPlayerInv.blocks[i].blockId==blockID)
		{
			space=i;
			i=NUM_INV_SPACES+1;
			//Skip other inventory spaces...
		}
	}	
	if (space==-1)
	{
		return 0;
	}
	if (blockID==AIR)
		return 64;
	return mainPlayerInv.blocks[space].blockAmount;
}

int getBlockID(int invSlot)
{
	return mainPlayerInv.blocks[invSlot].blockId;
}

int getBlockAmount(int invSlot)
{
	return mainPlayerInv.blocks[invSlot].blockAmount;
}

void clearInventory () //clears inventory
{
	int i;
	for (i=0;i<NUM_INV_SPACES;i++)
	{
		mainPlayerInv.blocks[i].blockAmount=0;
		mainPlayerInv.blocks[i].blockId=0;
	}
	updateInvGraphics();
	showingInventory = 0;
}

void changeGraphic(int blockID)
{
	if (loadedGraphic == true)
	{
		unloadGraphic(&heldBlock);
		loadedGraphic = false;	
	}
	loadGraphicSub(&heldBlock,2,blockID);
	loadedGraphic = true;
}

void updateInventory(touchPosition* touch, worldObject* world)
{
	if (!isSurvival())
		return;
	if (showingInventory == 0)
	{
		if (keysDown() & getKey(ACTION_SWITCH_SCREEN))
		{
			lcdMainOnTop();
			showingInventory = 1;
			miningSetScene(true);
			drawBackground();
			consoleClear();
			changeGraphic(AIR);
			drawButton(21,16,9);
			drawButton(9,16,10);
                        drawButton(1,16,5);
		}
	}
	else if (showingInventory == 1)
	{
		
		printXY(22, 17, "Crafting");
                printXY(10, 17, "Save Game");
		printXY(2, 17, "Back");
		showGraphic(&heldBlock,0,0,false,0);
		if (keysDown() & KEY_TOUCH)
		{
			if (touch->px > 8 && touch->py > 72 && touch->py < 120 && touch->px < 248) 
			{	
				
				int space = 0;
				space+=15*((touch->py - 72)/24);
				space+=(touch->px - 8)/16;
				if (selectedspace != -1 && !(mainPlayerInv.blocks[selectedspace].blockId==AIR))
				{
					//Swap the blocks.
					int tmpId, tmpAmount = 0;
					tmpId = mainPlayerInv.blocks[selectedspace].blockId;
					tmpAmount = mainPlayerInv.blocks[selectedspace].blockAmount;
					mainPlayerInv.blocks[selectedspace].blockId = mainPlayerInv.blocks[space].blockId;
					mainPlayerInv.blocks[selectedspace].blockAmount = mainPlayerInv.blocks[space].blockAmount;
					mainPlayerInv.blocks[space].blockId = tmpId;
					mainPlayerInv.blocks[space].blockAmount = tmpAmount;
					selectedspace = -1;
					setSelectedBlock(AIR);
					changeGraphic(AIR);
				}
				else
				{
					selectedspace = space;
					setSelectedBlock(mainPlayerInv.blocks[space].blockId);
					changeGraphic(mainPlayerInv.blocks[space].blockId);				
				}
			}
			else if (touch-> px > (2-1)*8 && touch->px < (2+5)*8 && touch->py > (17-1)*8 && touch->py < (17+2)*8)
			{
				//printXY(22, 17, "        ");
				printXY(1, 17, "      ");
				selectedspace = -1;
				lcdMainOnBottom();
				showingInventory = 0;
				miningSetScene(false);
				drawBackground();
                                drawButton(21,16,9);
                                drawButton(9,16,10);
			}
			else if (touch->px > (22-1)*8 && touch->px < (22+9)*8 && touch->py > (17-1)*8 && touch->py < (17+2)*8)
			{
				craftingMenuInit();
				showingInventory = 2;
				//show_message("Entering Crafing Menu\n");
			}
                        else if (touch->px > (10-1)*8 && touch->px < (10+10)*8 && touch->py > (17-1)*8 && touch->py < (17+2)*8)
			{
                            saveWorld(world);
                            show_message("Saved Game\n");
                        }
			else
			{
				selectedspace = -1;
				setSelectedBlock(AIR);
				changeGraphic(AIR);
			}
		}
		if (keysDown() & getKey(ACTION_SWITCH_SCREEN))
		{
			printXY(1, 17, "      ");
                        selectedspace = -1;
			lcdMainOnBottom();
			showingInventory = 0;
			miningSetScene(false);
			drawBackground();
                        drawButton(21,16,9);
                        drawButton(9,16,10);
		}
	}
	else if (showingInventory == 2)
	{
		if (craftingMenuUpdate())
		{
			//lcdMainOnTop();
			showingInventory = 1;
			miningSetScene(true);
			drawBackground();
			consoleClear();
			changeGraphic(AIR);
                        drawButton(21,16,9);
			drawButton(9,16,10);
                        drawButton(1,16,5);
			//show_message("Leaving Crafting Menu\n");
			enableInvGraphics();
		}
	}
}