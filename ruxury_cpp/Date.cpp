#include "Date.h"
Date::Date(int y, int m, int d) : year(y), month(m), day(d){}

Date::Date(string s)
{
	istringstream iss(s);
	string token;

	int date[3];
	int i = 0;
	while (getline(iss, token, '/')){
		date[i] = stoi(token);
		cout << date[i] << endl;
		i++;
	}
	year = date[0];
	month = date[1];
	day = date[2];
}

Date::~Date()
{
}

inline int Date::getYear(){ return year; }
inline int Date::getMonth(){ return month; }
inline int Date::getDay(){ return day; }

