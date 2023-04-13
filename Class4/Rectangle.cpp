#include "Rectangle.h"
#include<iostream>
using namespace std;
Rectangle::Rectangle(void):Pair() {
}
Rectangle::Rectangle(int tmp1, int tmp2):Pair(tmp1,tmp2) {
}
Rectangle::Rectangle(const Rectangle& t) {
	first = t.first;
	second = t.second;
}
Rectangle& Rectangle::operator=(const Rectangle&t) {
	first = t.first;
	second = t.second;
	return *this;
}
int Rectangle::get_perimeter() {
	return(2 * first + 2 * second);
}
int Rectangle::get_square() {
	return(first * second);
}

