#pragma once
#include <stdio.h>

class InvBlock
{
public:
	int ID = 0;
	int amount = 0;

	void saveToFile(FILE *file);
	void loadFromFile(FILE *file);

	InvBlock(int ID = 0, int amount = 0) : ID(ID), amount(amount) { }
};