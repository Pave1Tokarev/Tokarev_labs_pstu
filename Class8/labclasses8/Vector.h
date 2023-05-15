#pragma once
#include<iostream>
#include"Object.h"
using namespace std;
class Vector
{
public:
	Vector(void);
	Vector(int);
	~Vector();
	void show();
	void add(Object*);
	void del(void);
	void getname(int);
	friend ostream& operator<<(ostream& out, const Vector& t);
protected:
	Object** beg;
	int size;
	int current;
};

