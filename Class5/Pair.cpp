#include "Pair.h"
#include<iostream>
using namespace std;
void Pair::show() {
	cout << "Первое число: " << first << endl;
	cout << "Второе число: " << second << endl;
}
Pair::Pair(void) {
	first = 0;
	second = 0;
}
Pair::Pair(int tmp1, int tmp2) {
	first = tmp1;
	second = tmp2;
}
Pair::Pair(const Pair& t) {
	first = t.first;
	second = t.second;
}
Pair::~Pair(void) {

};
int Pair::get_first() {
	return first;
}
int Pair::get_second() {
	return second;
}
void Pair::set_first(int tmp) {
	first = tmp;
}
void Pair::set_second(int tmp) {
	second = tmp;
}
Pair& Pair::operator=(const Pair& t) {
	first = t.first;
	second = t.second;
	return *this;
}
istream& operator>>(istream& in, Pair& t) {
	cout << "Первое число:";
	in >> t.first;
	cout << "Второе число:";
	in >> t.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& t) {
	out << "Первое число:" << t.first;
	out << "Второе число:" << t.second;
	out << endl;
	return out;
}

int Pair::multyply() {
	return(first * second);
}