#include "Vector.h"
#include"Error.h"
#include<iostream>
using namespace std;
Vector::Vector(int sz) {
	size = sz;
	if (size > maxsize) {
		throw Error("Привышена максимальная длинна вектора");
	}
	mass = new int[sz];
	for (int i = 0;i < sz;i++) {
		mass[i] = 0;
	}
}
Vector::Vector(const Vector& t) {
	size = t.size;
	mass = new int[size];
	for (int i = 0;i < size;i++) {
		mass[i] = t.mass[i];
	}
}
Vector::~Vector() {
	delete[] mass;
	size = 0;
}
Vector& Vector::operator=(const Vector& t) {
	size = t.size;
	for (int i = 0;i < size;i++) {
		mass[i] = t.mass[i];
	}
	return *this;
}
int Vector::operator[](int index) {
	if (index < 0) {
		throw Error("индекс вышел за границы вектора(i<0)");
	}
	if (index >= size) {
		throw Error("Индекс вышел за границы вектора(i>=size)");
	}

	return mass[index];
}
Vector Vector::operator-(const Vector& t) {
	Vector tmp(t.size);
	for (int i = 0;i < t.size;i++) {
		tmp.mass[i] = mass[i] - t.mass[i];
	}
	return tmp;
}
Vector Vector::operator+(const Vector& t) {
	Vector tmp(t.size);
	for (int i = 0;i < t.size;i++) {
		tmp.mass[i] = mass[i] + t.mass[i];
	}
	return tmp;
}
int Vector::operator()() {
	return size;
}
ostream& operator<<(ostream& out, const Vector& t) {
	for (int i = 0;i < t.size;i++) {
		out << t.mass[i] << " ";
	}
	return out;
}
istream& operator>>(istream& in, Vector& t) {
	for (int i = 0;i < t.size;i++) {
		cout << (i + 1) << ":";
		in >> t.mass[i];
	}
	return in;
}
void Vector::operator+(int n) {
	if (n + size > maxsize) {
		throw Error("Невозможно добавить столько элементов");
	}
	for (int i = 0;i < n;i++) {
		cout << size << " : ";
		cin >> mass[size];
		size++;
	}
}
void Vector::operator-(int n) {
	if (size - n < 0) {
		throw Error("Невозможно удалить столько элементов");
	}
	if (n > size) {
		throw Error("В векторе нет столько элементов");
	}
	size -= n;
}