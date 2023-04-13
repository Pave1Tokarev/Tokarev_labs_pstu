#include "Rectangle.h"
#include<iostream>
using namespace std;
Rectangle::Rectangle(void) :Pair() {
	lenght = 0;
	width = 0;
}
Rectangle::Rectangle(int tmp1,int tmp2,int tmp3,int tmp4) :Pair(tmp1,tmp2) {
	lenght = tmp3;
	width = tmp4;
}
Rectangle::Rectangle(const Rectangle& t) {
	width = t.width;
	lenght = t.lenght;
}
void Rectangle::set_lenght(int t) {
	lenght = t;
}
int Rectangle::get_leght() {
	return lenght;
}
Rectangle& Rectangle::operator=(const Rectangle& t) {
	lenght = t.lenght;
	width = t.width;
	return *this;
}
int Rectangle::get_perimeter() {
	return(2 * lenght + 2 * width);
}
int Rectangle::get_square() {
	return(lenght * width);
}
Rectangle::~Rectangle(void) {
}
void Rectangle::show() {
	cout << "����� : " << lenght<<endl;
	cout << "������ : " << width << endl;
}
istream& operator>>(istream& in, Rectangle& t) {
	cout << "����� : ";
	in >> t.lenght;
	cout << "������ : ";
	in >> t.width;
	return in;
}
ostream& operator<<(ostream& out,const Rectangle& t) {
	out << "����� : ";
	out << t.lenght<<endl;
	out << "������ : ";
	out << t.width<<endl;
	return out;
}