#pragma once
#include"Pair.h"
class Rectangle:
	public Pair
{
public:
	Rectangle(void);
	Rectangle(int, int);
	Rectangle(const Rectangle& t);
	int get_leght();
	int get_width();
	void set_lenght(int);
	void set_width(int);
	Rectangle& operator=(const Rectangle&);
	friend istream operator>>(istream& in, Rectangle& t);
	friend ostream operator<<(ostream& out, const Rectangle& t);
	int get_square();
	int get_perimeter();
};

