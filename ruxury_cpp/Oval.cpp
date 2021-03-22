#include "Oval.h"


Oval::Oval() : width(1), height(1) {}

Oval::Oval(int w, int h){
	width = w;
	height = h;
}

Oval::~Oval()
{
	cout << "Oval ¼Ò¸ê : width = " << width << ", height = " << height << endl;
}

int Oval::getHeight(){
	return height;
}

int Oval::getWidth(){
	return width;
}

void Oval::set(int w, int h){
	width = w;
	height = h;

	
}

void Oval::show(){
	cout << "width = " << width << ", height = " << height << endl;
}
