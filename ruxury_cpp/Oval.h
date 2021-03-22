#pragma once
#include "main.h"

class Oval
{
	int width, height;
public:
	Oval();
	Oval(int w, int h);
	~Oval();

	int getWidth();
	int getHeight();
	void set(int w, int h);
	void show();
};

