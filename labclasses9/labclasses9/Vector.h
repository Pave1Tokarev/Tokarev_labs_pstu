#pragma once
#include<iostream>
using namespace std;
const int maxsize = 10;
class Vector
{
public:
	Vector(int t);
	Vector(const Vector& t);
	~Vector();
	int operator[](int index);
	Vector& operator=(const Vector& t);
	Vector operator+(const Vector& t);
	Vector operator-(const Vector& t);
	int operator() ();
	void operator+(int n);
	void operator-(int n);
	friend ostream& operator<<(ostream& out, const Vector& t);
	friend istream& operator>>(istream& in, Vector& t);
private:
	int size;
	int* mass;

};