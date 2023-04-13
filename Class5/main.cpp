#include<iostream>
#include"Object.h"
#include"Pair.h"
#include"Rectangle.h"
#include"Vector.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	Object* p;
	cout << "Прямоугольник a"<<endl;
	Rectangle a;
	cin >> a;
	cout << "Пара чисел b" << endl;
	Pair b;
	cin >> b;
	cout << "Выведем вектор c" << endl;
	Vector c(2);
	p = &a;
	c.add(p);
	p = &b;
	c.add(p);
	cout << c<<endl;
}
