#pragma once
#include <iostream>
using namespace std;
class Time {
public:
	Time(void);
	Time(int, int);
	Time(const Time&);
	~Time();
	int get_minute() {
		return minute;
	}
	int get_second() {
		return second;
	}
	friend ostream& operator<<(ostream& out, const Time&);
	friend istream& operator>>(istream& in, Time&);
	Time& operator=(const Time&a);
	Time operator-(const Time&);
	friend Time operator+(const Time&a,const Time&b);
	bool operator!=(const Time&);
	bool operator==(const Time&);
	friend bool operator<(const Time& a,const Time&b) ;
	friend bool operator>(const Time& a, const Time& b);
protected:
	int minute;
	int second;
};