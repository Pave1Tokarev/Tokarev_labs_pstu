#include "Vector.h"
#include<iostream>
using namespace std;
Vector::Vector() {
	beg = 0;
	size = 0;
	current = 0;
}
Vector::~Vector() {
	if (beg != 0) {
		delete[] beg;
	}
	beg = 0;
}
Vector::Vector(int n) {
	beg = new Object * [n];
	current = 0;
	size = n;
}
void Vector::add(Object* p) {
	if (current < size) {
		beg[current] = p;
		current++;
	}
}
void Vector::del() {
	beg[current] = 0;
	current--;
}
ostream& operator<<(ostream& out, const Vector& t) {
	if (t.size == 0) {
		cout << "Вектор пуст" << endl;
	}
	Object** p = t.beg;
	for (int i = 0;i < t.size;i++) {
		(*p)->show();
		p++;
	}
	return out;
}
void Vector::show() {
	Object** pt = beg;
	cout << "           Группа" << endl << endl;;
	for (int i = 0;i < current;i++) {
		(*pt)->show();
		pt++;
		cout << endl;
	}
}
void Vector::getname(int k) {
	Object** pt = beg;
	for (int i = 0;i < k;i++) {
		pt++;
	}
	cout << (*pt)->get_name()<<endl;
}