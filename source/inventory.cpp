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
#include "graphics/Button.h"
#include "graphics/UI.h"
#include "crafting.h"
#include "inventory.h"
#include "blockID.h"
#include "blocks.h"
#include "general.h"
#include "mainGame.h" // for isSurvival
#include <nds.h> // for keysDown()
#include "Config.h"
#include "world.h"
#include "files.h"
#include "graphics/Button.h"
#include "blockPages.h"
#include "blockName.h"
#include "chests.h"
bool loadedTopGraphic = false;
int invSlot = -1;
int oldInvSlot;
Graphic selectedGraphic;
int loadedGraphic;
Button backButton(1, 16, "Back", false);
Button saveButton(8, 16, "Save World", false);
Button craftButton(21, 16, "Crafting", false);
Button pageButton(21, 16, "Pages", 9, false);
unsigned char oldX, oldY;

/*					A reminder:
 * INVENTORY STRUCT USES blockId, not blockID, for what ever reason!!!!!
 */

void changeInvSelectedGraphic(int blockID)
{
	if (loadedTopGraphic)
		unloadGraphic(&selectedGraphic);
	if (blockID == -1)
	{
		if (invSlot<-1 && getOpenedChestID() != -1)
		{
			loadGraphicSub(&selectedGraphic, GRAPHIC_BLOCK, getChestBlockID(-invSlot - 2));
			drawSlots(-invSlot - 2, 1, 1);
			drawSlots(invSlot, 1, 9);
			loadedGraphic = getChestBlockID(-invSlot - 2);
		}
		else if (invSlot >= 0)
		{
			loadGraphicSub(&selectedGraphic, GRAPHIC_BLOCK, getBlockID(invSlot));
			drawSlots(invSlot, 1, 9);
			if (getOpenedChestID() != -1)
				drawSlots(-1, 1, 1);
			loadedGraphic = getBlockID(invSlot);
		}
		else
		{
			loadGraphicSub(&selectedGraphic, GRAPHIC_BLOCK, AIR);
			drawSlots(-1, 1, 9);
			if (getOpenedChestID() != -1)
				drawSlots(-1, 1, 1);
			loadedGraphic = AIR;
		}
		updateTopName(getBlockID(invSlot));
	}
	else
	{
		loadGraphicSub(&selectedGraphic, GRAPHIC_BLOCK, blockID);
		updateTopName(blockID);
		loadedGraphic = blockID;
	}
	loadedTopGraphic = true;
}

int getSelectedSlot()
{
	return invSlot;
}

void setSelectedSpace(int space)
{
	invSlot = space;
	changeInvSelectedGraphic();
}

int showingInventory;
Inventory mainPlayerInv;

void drawInvButtons(bool drawBack, bool survival)
{
	if (drawBack) backButton.draw();
	saveButton.draw();
	if (survival)
		craftButton.draw();
	else
		pageButton.draw();
}

void saveInventory(FILE* data)
{
	for (int i = 0; i < NUM_INV_SPACES; ++i)
		fprintf(data, "%d %d ", mainPlayerInv.blocks[i].blockId, mainPlayerInv.blocks[i].blockAmount);
}

int getInventoryState()
{
	return showingInventory;
}

int spaceForItem(int blockID)
{
	int space = -1;
	for (int i = 0; i < NUM_INV_SPACES; ++i)
	{
		//Found the correct block with correct id.
		if (mainPlayerInv.blocks[i].blockId == blockID && mainPlayerInv.blocks[i].blockAmount < 64)
		{
			space = i;
			break;
			//Skip other inventory spaces...
		}
			//Found a sutiable air space.
		else if (mainPlayerInv.blocks[i].blockId == AIR)
		{
			//Set the space as last resort, try to find correct inventory space.
			space = i;
		}
	}
	if (space == -1)
		printLocalMessage("No space for item");
	return space;
}

bool addInventory(int blockID, int amount, bool direct) //adds the specified amount to a blockvalue
{
	if (blockID == AIR)
		return false;
	int space = spaceForItem(blockID);
	if (space == -1)
		return false;
	mainPlayerInv.blocks[space].blockId = blockID;
	if (isSurvival())
		mainPlayerInv.blocks[space].blockAmount += amount;
	else
		mainPlayerInv.blocks[space].blockAmount = 1;
	if (!direct)
		updateInvGraphics();
  return true;
}

bool addInventory(int blockID)
{
  return addInventory(blockID, 1);
}

bool subInventory(int blockID, int amount) //subtracts the specified amount to a blockvalue
{
	if (isSurvival() == false) //Always return true in creative!
		return true;
	int i;
	int space = -1;
	for (i = 0; i < NUM_INV_SPACES; ++i)
	{
		//Found the correct block with correct id.
		if (mainPlayerInv.blocks[i].blockId == blockID)
		{
			space = i;
			break;
			//Skip other inventory spaces...
		}
	}
	if (space == -1)
		return false;
	mainPlayerInv.blocks[space].blockAmount -= amount;
	if (mainPlayerInv.blocks[space].blockAmount < 0)
	{
		mainPlayerInv.blocks[space].blockAmount += amount;
		return false;
	}
	else if (mainPlayerInv.blocks[space].blockAmount == 0)
		mainPlayerInv.blocks[space].blockId = AIR;
	updateInvGraphics();
	return true;
}

int getInventorySlot(int blockID) //returns slot of blockid in inventory
{
	int space = -1;
	for (int i = 0; i < NUM_INV_SPACES; ++i)
	{
		//Found the correct block with correct id.
		if (mainPlayerInv.blocks[i].blockId == blockID)
		{
			space = i;
			break;
		}
	}
	return space;
}

int checkInventory(int blockID) //returns quantity of blockid in inventory
{
	if (blockID == AIR)
		return 64;
	int space = getInventorySlot(blockID);
	if (space == -1)
		return 0;
	return mainPlayerInv.blocks[space].blockAmount;
}

int checkInventorySlot(int slot)
{
	return mainPlayerInv.blocks[slot].blockAmount;
}

int getBlockID(int invSlot)
{
	if (invSlot>-1)
		return mainPlayerInv.blocks[invSlot].blockId;
	else if (invSlot<-1 && getOpenedChestID() != -1)
		return getChestBlockID(-invSlot - 2);
	else
		return AIR;

}

int getBlockAmount(int invSlot)
{
	return mainPlayerInv.blocks[invSlot].blockAmount;
}

void clearInventory(bool direct) //clears inventory
{
	int i;
	for (i = 0; i < NUM_INV_SPACES; ++i)
	{
		mainPlayerInv.blocks[i].blockAmount = 0;
		mainPlayerInv.blocks[i].blockId = 0;
	}
	if (!direct)
		updateInvGraphics();
	showingInventory = 0;
}

void openInventory()
{
	oldInvSlot = invSlot;
	invSlot = -1;
	changeInvSelectedGraphic();
	lcdMainOnTop();
	showingInventory = 1;
	setMiningDisabled(true);
	backButton.setVisible(true);
	saveButton.setVisible(true);
	craftButton.setVisible(isSurvival());
	pageButton.setVisible(!isSurvival());
}

void closeInventory()
{
	if (invSlot == -1)
		invSlot = oldInvSlot;
	closeChest();
	lcdMainOnBottom();
	showingInventory = 0;
	setMiningDisabled(false);
	backButton.setVisible(false);
	saveButton.setVisible(false);
	craftButton.setVisible(false);
	pageButton.setVisible(false);
	clearText();
	drawBackground();
	drawInvButtons(false, isSurvival());
	updateInvGraphics();
	updatePageName();
}

void moveSlotRecursive(bool right, int origSlot, bool first)
{
	bool *startOnBlock = new bool(getBlockID(invSlot) != AIR);
	if (invSlot == -1 || (invSlot<-1 && getOpenedChestID() == -1))
		invSlot = right ? (getOpenedChestID() == -1 ? 0 : -2) : (NUM_INV_SPACES - 1);
	else if (invSlot<-1)
	{
		invSlot += right ? -1 : 1;
		if (invSlot>-2)
			invSlot = -1;
		else if (invSlot < -CHEST_SLOTS - 1)
			invSlot = 0;
	}
	else
	{
		invSlot += right ? 1 : -1;
		if (invSlot >= NUM_INV_SPACES) invSlot = -1;
		else if (invSlot < 0) invSlot = getOpenedChestID() == -1 ? (-1) : (-CHEST_SLOTS - 1);
	}
	if (getBlockID(invSlot) == AIR&&!*startOnBlock && (invSlot != origSlot || first))
	{
		delete startOnBlock;
		moveSlotRecursive(right, origSlot, false);
	}
}

void moveSelectedSlot(bool right)
{
	moveSlotRecursive(right, invSlot, true);
	changeInvSelectedGraphic();
}

void updateInventory(touchPosition touch, WorldObject* world, uint oldKeys)
{
	if (showingInventory != 2) //Not in crafting menu
	{
		showGraphic(&selectedGraphic, 8, 6 * 8 + (getOpenedChestID() == -1 ? 0 : 4), false, 0);
		if (keysDown() & getGlobalSettings()->getKey(ACTION_ITEM_LEFT))
		{
			if (!isSurvival() && keysHeld() & getGlobalSettings()->getKey(ACTION_CROUCH))
				changeBlockPage(false);
			else
				moveSelectedSlot(false);
		}
		else if (keysDown() & getGlobalSettings()->getKey(ACTION_ITEM_RIGHT))
		{
			if (!isSurvival() && keysHeld() & getGlobalSettings()->getKey(ACTION_CROUCH))
				changeBlockPage(true);
			else
				moveSelectedSlot(true);
		}
	}

	switch (showingInventory)
	{
		case 0:
			if (keysDown() & getGlobalSettings()->getKey(ACTION_SWITCH_SCREEN))
				openInventory();
			break;
		case 1:
			if (keysHeld() & KEY_TOUCH && !(oldKeys & KEY_TOUCH)) //New Press
			{
				touchRead(&touch);
				backButton.setColored(backButton.isTouching(touch.px, touch.py));
				saveButton.setColored(saveButton.isTouching(touch.px, touch.py));
				craftButton.setColored(craftButton.isTouching(touch.px, touch.py));
				pageButton.setColored(pageButton.isTouching(touch.px, touch.py));
			}
			else if (!(keysHeld() & KEY_TOUCH) && oldKeys & KEY_TOUCH) //Release
			{
				if (oldX > 1 * 8 && oldY > (8 + 1)*8 && oldY < (8 + 6)*8 && oldX < 31 * 8)
				{
					int space = 0;
					space += 15 * ((oldY - (8 + 1)*8) / (3 * 8));
					space += (oldX - 8) / 16;
					if (getOpenedChestID() != -1 && invSlot<-1 && world->chests[getOpenedChestID()][-invSlot - 2][INDEX_BLOCK_ID] != AIR)
					{ //Source: Chest, Destination: Inventory
						int tmpId, tmpAmount = 0;
						tmpId = world->chests[getOpenedChestID()][-invSlot - 2][INDEX_BLOCK_ID];
						tmpAmount = world->chests[getOpenedChestID()][-invSlot - 2][INDEX_AMOUNT];
						world->chests[getOpenedChestID()][-invSlot - 2][INDEX_BLOCK_ID] = mainPlayerInv.blocks[space].blockId;
						world->chests[getOpenedChestID()][-invSlot - 2][INDEX_AMOUNT] = mainPlayerInv.blocks[space].blockAmount;
						mainPlayerInv.blocks[space].blockId = tmpId;
						mainPlayerInv.blocks[space].blockAmount = tmpAmount;
						invSlot = -1;
						setSelectedSpace(-1);
						changeInvSelectedGraphic(AIR);
					}
					else if (invSlot > -1 && !(mainPlayerInv.blocks[invSlot].blockId == AIR))
					{ //Source: Inventory, Destination:Inventory
						int tmpId, tmpAmount = 0;
						tmpId = mainPlayerInv.blocks[invSlot].blockId;
						tmpAmount = mainPlayerInv.blocks[invSlot].blockAmount;
						mainPlayerInv.blocks[invSlot].blockId = mainPlayerInv.blocks[space].blockId;
						mainPlayerInv.blocks[invSlot].blockAmount = mainPlayerInv.blocks[space].blockAmount;
						mainPlayerInv.blocks[space].blockId = tmpId;
						mainPlayerInv.blocks[space].blockAmount = tmpAmount;
						invSlot = -1;
						setSelectedSpace(-1);
						changeInvSelectedGraphic(AIR);
					}
					else if (keysHeld() & getGlobalSettings()->getKey(ACTION_CROUCH) && getOpenedChestID() != -1)
					{
						int chestID = getOpenedChestID();
						for (int i = 0; i < CHEST_SLOTS; ++i)
							if (world->chests[chestID][i][INDEX_BLOCK_ID] == AIR || world->chests[chestID][i][INDEX_AMOUNT] == AIR)
							{
								int tmpId, tmpAmount = 0;
								tmpId = mainPlayerInv.blocks[space].blockId;
								tmpAmount = mainPlayerInv.blocks[space].blockAmount;
								mainPlayerInv.blocks[space].blockId = world->chests[getOpenedChestID()][i][INDEX_BLOCK_ID];
								mainPlayerInv.blocks[space].blockAmount = world->chests[getOpenedChestID()][i][INDEX_AMOUNT];
								world->chests[getOpenedChestID()][i][INDEX_BLOCK_ID] = tmpId;
								world->chests[getOpenedChestID()][i][INDEX_AMOUNT] = tmpAmount;
								invSlot = -1;
								setSelectedSpace(getInventorySlot(-1));
								changeInvSelectedGraphic(AIR);
								break;
							}
					}
					else
					{
						invSlot = space;
						setSelectedSpace(space);
						changeInvSelectedGraphic(mainPlayerInv.blocks[space].blockId);
					}
					updateChestItems();
					updateInvGraphics();
				}
				else if (getOpenedChestID() != -1 && oldX > 1 * 8 && oldY > 1 * 8 && oldY < 6 * 8 && oldX < 31 * 8)
				{
					int space = 0;
					space += 15 * ((oldY - 1 * 8) / (3 * 8));
					space += (oldX - 8) / 16;
					if (invSlot > -1 && mainPlayerInv.blocks[invSlot].blockId != AIR)
					{ //Source: Inventory, Destination: Chest
						int tmpId, tmpAmount = 0;
						tmpId = mainPlayerInv.blocks[invSlot].blockId;
						tmpAmount = mainPlayerInv.blocks[invSlot].blockAmount;
						mainPlayerInv.blocks[invSlot].blockId = world->chests[getOpenedChestID()][space][INDEX_BLOCK_ID];
						mainPlayerInv.blocks[invSlot].blockAmount = world->chests[getOpenedChestID()][space][INDEX_AMOUNT];
						world->chests[getOpenedChestID()][space][INDEX_BLOCK_ID] = tmpId;
						world->chests[getOpenedChestID()][space][INDEX_AMOUNT] = tmpAmount;
						invSlot = -1;
						setSelectedSpace(getInventorySlot(-1));
						changeInvSelectedGraphic(AIR);
					}
					else if (invSlot < -1 && world->chests[getOpenedChestID()][-invSlot - 2][INDEX_BLOCK_ID] != AIR)
					{ //Source: Chest, Destination: Chest
						int tmpId, tmpAmount = 0;
						tmpId = world->chests[getOpenedChestID()][-invSlot - 2][INDEX_BLOCK_ID];
						tmpAmount = world->chests[getOpenedChestID()][-invSlot - 2][INDEX_AMOUNT];
						world->chests[getOpenedChestID()][-invSlot - 2][INDEX_BLOCK_ID] = world->chests[getOpenedChestID()][space][INDEX_BLOCK_ID];
						world->chests[getOpenedChestID()][-invSlot - 2][INDEX_AMOUNT] = world->chests[getOpenedChestID()][space][INDEX_AMOUNT];
						world->chests[getOpenedChestID()][space][INDEX_BLOCK_ID] = tmpId;
						world->chests[getOpenedChestID()][space][INDEX_AMOUNT] = tmpAmount;
						invSlot = -1;
						setSelectedSpace(-1);
						changeInvSelectedGraphic(AIR);
					}
					else if (keysHeld() & getGlobalSettings()->getKey(ACTION_CROUCH))
					{
						addInventory(world->chests[getOpenedChestID()][space][INDEX_BLOCK_ID], world->chests[getOpenedChestID()][space][INDEX_AMOUNT], true);
						world->chests[getOpenedChestID()][space][INDEX_BLOCK_ID] = AIR;
						world->chests[getOpenedChestID()][space][INDEX_AMOUNT] = 0;
						invSlot = -1;
						setSelectedSpace(-1);
						changeInvSelectedGraphic(AIR);
					}
					else
					{
						invSlot = -space - 2;
						setSelectedSpace(-space - 2);
						changeInvSelectedGraphic(world->chests[getOpenedChestID()][-invSlot - 2][INDEX_BLOCK_ID]);
					}
					updateChestItems();
					updateInvGraphics();
				}
				else if (backButton.isColored && backButton.isTouching(oldX, oldY))//(touch. px > (2 - 1)*8 && oldX < (2 + 5)*8 && oldY > (17 - 1)*8 && oldY < (17 + 2)*8)
					closeInventory();
				else if (craftButton.isColored && craftButton.isTouching(oldX, oldY))
				{ //Crafting Menu
					backButton.setVisible(false);
					saveButton.setVisible(false);
					craftButton.setVisible(false);
					pageButton.setVisible(false);
					craftingMenuInit();
					showingInventory = 2;
				}
				else if (saveButton.isColored && saveButton.isTouching(oldX, oldY))
				{ //Save Game
					if (saveWorld(world))
						printLocalMessage("Saved Game\n");
					else
						printLocalMessage("Failed to Save Game\n");
					saveButton.setColored(false);
				}
				else if (pageButton.isColored && pageButton.isTouching(oldX, oldY))
				{ //Page Menu
					backButton.setVisible(false);
					saveButton.setVisible(false);
					craftButton.setVisible(false);
					pageButton.setVisible(false);
					pageMenuInit();
					showingInventory = 2;
				}
				else
				{
					invSlot = -1;
					setSelectedSpace(-1);
					changeInvSelectedGraphic(AIR);
					backButton.setColored(false);
					saveButton.setColored(false);
					craftButton.setColored(false);
					pageButton.setColored(false);
				}
			}
			if (keysDown() & getGlobalSettings()->getKey(ACTION_SWITCH_SCREEN))
				closeInventory();
			oldX = touch.px;
			oldY = touch.py;
			break;
		case 2:
			if ((isSurvival() && craftingMenuUpdate(&touch, &oldX, &oldY, &oldKeys)) || (!isSurvival() && pageMenuUpdate(&touch, &oldX, &oldY, &oldKeys)))
			{ //Leaving crafting/page menu
				showingInventory = 1;
				setMiningDisabled(true);
				drawBackground();
				clearText();
				changeInvSelectedGraphic(AIR);
				backButton.setVisible(true);
				saveButton.setVisible(true);
				craftButton.setVisible(isSurvival());
				pageButton.setVisible(!isSurvival());
				enableInvGraphics();
				updatePageName();
			}
			else
			{
				oldX = touch.px;
				oldY = touch.py;
			}
			break;
	}
	drawInv();
}

void loadInventory(FILE* data)
{
	clearInventory();
	for (int i = 0; i < NUM_INV_SPACES; ++i)
	{
		int id, quantity;
		fscanf(data, "%d %d ", &id, &quantity);
		addInventory(id, quantity, true);
	}
}
