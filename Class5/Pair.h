#pragma once
#include<iostream>
#include"Object.h"
using namespace std;
class Pair:
	public Object
{
public:
	Pair(void);
	Pair(int, int);
	Pair(const Pair&);
	void show();
	virtual ~Pair(void);
	int get_first();
	int get_second();
	void set_first(int);
	void set_second(int);
	Pair& operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& t);
	friend ostream& operator<<(ostream& out, const Pair& t);
	int multyply();
private:
	int first;
	int second;
};

