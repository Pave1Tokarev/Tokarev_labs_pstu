#pragma once
#include<iostream>
#include "iterator.h"
using namespace std;

class vector
{
public:
	vector(int t);
	vector(const vector& t);
	~vector();
	int operator[](int index);
	vector& operator=(const vector& t);
	vector operator+(const vector& t);
	vector operator-(const vector& t);
	int operator() ();
	friend ostream& operator<<(ostream& out, const vector& t);
	friend istream& operator>>(istream& in, vector& t);
	Iterator first();
	Iterator last();
	void fillrandom(int sz);
private:
	int size;
	int* mass;
	Iterator start;
	Iterator end;

};
