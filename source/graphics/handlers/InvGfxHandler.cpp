#include "InvGfxHandler.h"
#include "../subBgHandler.h"
#include "../graphics.h"
#include "../../general.h"
#include "../UI.h"

void InvGfxHandler::drawSlots(bool drawSelected)
{
	int slot = 0;
	for (int j = 0; j < yCount; ++j)
		for (int i = 0; i < xCount; ++i)
		{
			int tile = 154;
			if (slot == inv.hand && drawSelected)
				tile = 155;
			drawInvSlot(startX + i*xDist, startY + j*yDist, tile);
			++slot;
		}
}

void InvGfxHandler::drawQuantities()
{
	for (int i = 0; i < xCount; ++i)
		for (int j = 0; j < yCount; ++j)
			if (inv.blocks[j * xCount + i].blockAmount != 0 && inv.blocks[j * xCount + i].blockId != 0)
			{
				printXY(startX + i * xDist, startY + 1 + j * yDist, inv.blocks[j * xCount + i].blockAmount);
				if (inv.blocks[j * 15 + i].blockAmount < 10)
					printXY(startX + i * xDist + 1, startY + 1 + j * yDist, " ");
			}
			else
				printXY(startX + i * xDist, startY + 1 + j * yDist, "  ");
}

void InvGfxHandler::update()
{
	int a = 0;
	for (int i = 0; i < yCount; ++i)
		for (int j = 0; j < xCount; ++j)
		{
			if (inv.blocks[a].blockId == AIR && loadedGfx[a])
			{
				unloadGraphic(&gfx[a]);
				loadedGfx[a] = false;
				loadedID[a] = AIR;
			}
			else if (inv.blocks[a].blockId != loadedID[a])
			{
				if (loadedGfx[a])
					unloadGraphic(&gfx[a]);
				else
					loadedGfx[a] = true;
				loadGraphicSub(&gfx[a], GRAPHIC_BLOCK, inv.blocks[a].blockId);
				loadedID[a] = inv.blocks[a].blockId;
			}
			if (loadedGfx[a])
				showGraphic(&gfx[a], startX * 8 + j * 8 * xDist, startY * 8 + i * 8 * yDist, false, 2);
			++a;
		}
}