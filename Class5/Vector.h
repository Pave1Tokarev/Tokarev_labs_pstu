#pragma once
#include<iostream>
#include"Object.h"
class Vector
{
public:
	Vector(void);
	Vector(int);
	~Vector(void);
	void add(Object*);
	friend ostream& operator<<(ostream& out, const Vector&);
private:
	Object** beg;
	int size;
	int current;
};

