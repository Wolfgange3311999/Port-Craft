/*
        -----------------------------------------
        |             Inventory.cpp             |
        |           Inventory Funtions          |
        -----------------------------------------
*/
#include "mining.h" //for NUM_BLOCKS
int inventory[NUM_BLOCKS];
void addInventory(int blockID, int amount) //adds the specified amount to a blockvalue
{
	inventory [blockID] += amount;
}
void subInventory (int blockID, int amount) //subtracts the specified amount to a blockvalue
{
	inventory [blockID] -= amount;
}
int checkInventory (int blockID) //returns quantity of blockid in inventory
{
	return inventory [blockID];
}
void clearInventory () //clears inventory
{
	int i;
	for (i = 0; i <= NUM_BLOCKS; i++)
		inventory [i] = 0;
}