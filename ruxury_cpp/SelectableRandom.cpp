#include "SelectableRandom.h"


SelectableRandom::SelectableRandom()
{
}


SelectableRandom::~SelectableRandom()
{
}

int SelectableRandom::next(){
	return rand();
}

int SelectableRandom::nextInRange(int r1, int r2){
	return r1 + rand() % r2;
}