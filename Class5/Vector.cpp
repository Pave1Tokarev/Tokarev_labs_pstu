#include "Vector.h"
#include<iostream>
using namespace std;
Vector::Vector(void) {
	beg = 0;
	size = 0;
	current = 0;
}
Vector::~Vector(void) {
	if (beg != 0) {
		delete[] beg;
	}
	beg = 0;
}
Vector::Vector(int n) {
	beg = new Object*[n];
	current = 0;
	size = n;
}
void Vector::add(Object* p) {
	if (current < size) {
		beg[current] = p;
		current++;
	}
}
ostream& operator<<(ostream& out, const Vector& t) {
	if (t.size == 0) {
		out << "Вектор пуст";
	}
	Object** p = t.beg;
	for (int i = 0;i < t.current;i++) {
		(*p)->show();
		p++;
	}
	return out;
}