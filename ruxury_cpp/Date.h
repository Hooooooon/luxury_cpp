#pragma once
#include "main.h"
#include <sstream>
#include <string>

class Date
{
	int year, month, day;
public:
	Date(int y, int m, int d);
	Date(string s);
	~Date();

	inline int getYear();
	inline int getMonth();
	inline int getDay();
	inline void show(){
		cout << year << ", " << month << ", " << day << endl;
	}
};

