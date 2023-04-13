#pragma once
#include<iostream>
using namespace std;
class Pair
{
public:
	int first;
	int second;
	Pair();
	Pair(int, int);
	Pair(const Pair&);
	~Pair();
	int get_first();
	int get_second();
	void set_first(int);
	void set_second(int);
	Pair& operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& t);
	friend ostream& operator<<(ostream& out, const Pair& t);
	int multyply();
};

