#include "stack.h"
#include<iostream>
using namespace std;
stack::stack() {
	count = 0;
	arr = new int[10000];
}
stack::stack(const stack& a) {
	count = a.count;
	for (int i = 0;i < count;i++) {
		arr[i] = a.arr[i];
	}
}
stack::stack(int n) {
	int tmp;
	count = n;
	arr = new int[10000];
	for (int i = 0;i < n;i++) {
		cout << i + 1 << " : ";
		cin >> tmp;
		push_top(tmp);
	}
}
stack::~stack() {
	delete[]arr;
}
void stack::push_top(int n) {
	arr[count] = n;
	count++;
}
void stack::pop_top() {
	count--;
}
void stack::show() {
	cout << endl << "top" << endl;
	int sz = count;
	for (int i = sz -1;i >=0;i--) {
		cout << arr[i] << endl;
	}
	cout << "bottom" << endl;
}
void stack::delete_stack() {
	count = 0;
}
int stack::operator()() {
	return count;
}
int stack::operator[](int index) {
	if (index < count) {
		return arr[index];
	}
}
stack& stack::operator=(const stack& t) {
	count = t.count;
	for (int i = 0;i < count;i++) {
		arr[i] = t.arr[i];
	}
	return*this;
}
stack stack::operator+(const stack& t) {
	stack a(t.count);
	for (int i = 0;i < t.count;i++) {
		a.arr[i] = arr[i] + t.arr[i];
	}
	return a;
}
stack stack::operator-(const stack& t) {
	stack a(t.count);
	for (int i = 0;i < t.count;i++) {
		a.arr[i] = arr[i] - t.arr[i];
	}
	return a;
}
int stack::get_top() {
	return arr[count - 1];
}
