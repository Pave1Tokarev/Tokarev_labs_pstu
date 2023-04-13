#include "vector.h"
#include"iterator.h"
#include<iostream>
using namespace std;
vector::vector(int sz) {
	size = sz;
	mass = new int[sz];
	for (int i = 0;i < sz;i++) {
		mass[i] = 0;
	}
	start.elem = &mass[0];
	end.elem = &mass[sz - 1];
}
vector::vector(const vector& t) {
	size = t.size;
	mass = new int[size];
	for (int i = 0;i < size;i++) {
		mass[i] = t.mass[i];
	}
	start = t.start;
	end = t.end;
}
vector::~vector() {
	delete[] mass;
	size = 0;
}
vector& vector::operator=(const vector& t) {
	size = t.size;
	for (int i = 0;i < size;i++) {
		mass[i] = t.mass[i];
	}
	start = t.start;
	end = t.end;
	return *this;
}
int vector::operator[](int index) {
	if (index < size) {
		return mass[index];
	}
	else {
		return -1;
	}
}
vector vector::operator-(const vector& t) {
	vector tmp(t.size);
	for (int i = 0;i < t.size;i++) {
		tmp.mass[i] = mass[i] - t.mass[i];
	}
	return tmp;
}
vector vector::operator+(const vector& t) {
	vector tmp(t.size);
	for (int i = 0;i < t.size;i++) {
		tmp.mass[i] = mass[i] + t.mass[i];
	}
	return tmp;
}
int vector::operator()() {
	return size;
}
ostream& operator<<(ostream& out, const vector& t) {
	for (int i = 0;i < t.size;i++) {
		out << t.mass[i] << " ";
	}
	return out;
}
istream& operator>>(istream& in,vector& t) {
	for (int i = 0;i < t.size;i++) {
		cout << (i+1)<<":";
		in >> t.mass[i];
	}
	return in;
}
Iterator vector::first() {
	return start;
}
Iterator vector::last() {
	return end;
}
void vector::fillrandom(int sz) {
	for (int i = 0;i < sz;i++) {
		mass[i] = rand() % 100;
	}
}