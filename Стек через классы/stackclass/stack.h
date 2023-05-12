#pragma once
#include<iostream>
using namespace std;
class stack
{
private:
	int count;
	int *arr;
public:
	stack();
	stack(int n);
	stack(const stack&a);
	~stack();
	int operator[](int index);
	int operator()();
	int get_top();
	stack& operator=(const stack& t);
	stack operator+(const stack& t);
	stack operator-(const stack& t);
	void push_top(int a);
	void pop_top();
	void show();
	void delete_stack();
	friend ostream& operator<<(ostream& out, const stack& t) {
		out << "top" << endl;
		for (int i = 0;i < t.count;i++) {
			out << t.arr[i] << endl;
		}
		out << "bottom" << endl;
		return out;
	}
	friend istream& operator>>(istream& in, stack& t) {
		for (int i = 0;i < t.count;i++) {
			cout << i + 1 << " : ";
			in >> t.arr[i];
		}
		return in;
	}
};