#include "Time.h"
#include <iostream>
using namespace std;
Time &Time::operator=(const Time& t) {
	if (&t == this) {
		return *this;
	}
	else {
	min = t.min;
	sec = t.sec;
	return *this;
	}
}
Time Time::operator-(const Time& t) {
	int tmp1 = (min * 60) + sec;
	int tmp2 = (t.min * 60) + t.sec;
	Time newtime;
	newtime.min = (tmp1 - tmp2) / 60;
	newtime.sec = (tmp1 - tmp2) % 60;
	return newtime;
}
bool Time::operator!=(const Time& t) {
	if ((min != t.min) && (sec != t.sec)) {
		return true;
	}
	else {
		return false;
	}
};
istream& operator>>(istream& in, Time& t) {
	cout << "минута:";
	in >> t.min;
	cout << "секунда:";
	in >> t.sec;
	return in;
}
ostream& operator<<(ostream& out, const Time& t) {
	return (out << t.min << ":" << t.sec);
}