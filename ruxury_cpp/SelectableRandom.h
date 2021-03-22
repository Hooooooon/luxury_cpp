#pragma once
#include "main.h"

class SelectableRandom
{
public:
	SelectableRandom();
	~SelectableRandom();
	
	int next();
	int nextInRange(int r1, int r2);
}typedef Random;

