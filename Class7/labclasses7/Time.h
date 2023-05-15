#pragma once
#include <iostream>
using namespace std;
class Time {
public:
	int minute;
	int second;
	Time(void);
	Time(int, int);
	Time(const Time&);
	~Time();
	friend ostream& operator<<(ostream&out,const Time&);
	friend istream& operator>>(istream& in, Time&);
	Time& operator=(const Time&);
	Time operator-(const Time&);
	Time operator+(const Time&);
	bool operator!=(const Time&);
};