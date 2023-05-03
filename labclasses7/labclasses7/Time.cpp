#include "Time.h"
#include<iostream>
using namespace std;
Time::Time() {
	minute = 0;
	second = 0;
}
Time::Time(int a, int b) {
	minute = a;
	second = b;
}
Time::Time(const Time&a) {
	minute = a.minute;
	second = a.second;
}
Time::~Time() {

}
ostream& operator<<(ostream& out, const Time& a) {
	out << a.minute << ":" << a.second;
	return out;
}
Time Time::operator+(const Time& a) {
	int tmp1 = (minute * 60) + second;
	int tmp2 = (a.minute * 60) + a.second;
	Time newtime;
	newtime.minute = (tmp1 + tmp2) / 60;
	newtime.second = (tmp1 + tmp2) % 60;
	return newtime;

}
istream& operator>>(istream& in,Time& a) {
	cout << "Минута:";
	in >> a.minute;
	cout << "Секунда:";
	in >> a.second;
	return in;
}
Time& Time::operator=(const Time& t) {
	if (&t == this) {
		return *this;
	}
	else {
		minute = t.minute;
		second = t.second;
		return *this;
	}
}
Time Time::operator-(const Time& t) {
	int tmp1 = (minute * 60) + second;
	int tmp2 = (t.minute * 60) + t.second;
	Time newtime;
	newtime.minute = (tmp1 - tmp2) / 60;
	newtime.second = (tmp1 - tmp2) % 60;
	return newtime;
}
bool Time::operator!=(const Time& t) {
	if ((minute != t.minute) && (second != t.second)) {
		return true;
	}
	else {
		return false;
	}
};