#pragma once
#include <iostream>
#include"Time.h"
#include<vector>
using namespace std;
template <typename t>
class Vector {
private:
	int  size;
	vector<t> mass;
public:
	Vector(int s, t k) {
		size = s;
		for (int i = 0;i < size;i++) {
			mass.push_back(k);
		}
	}
	Vector(const Vector<t>& a) {
		size = a.size;
		for (int i = 0;i < a.size;i++) {
			mass.push_back(a.mass[i]);
		}
	}
	~Vector() {
	}
	friend ostream& operator<<(ostream& out, const Vector<t>& a) {
		for (int i = 0;i < a.size;i++) {
			out << i + 1 << "  " << a.mass[i] << endl;
		}
		return out;
	}
	friend istream& operator>>(istream& in, Vector<t>& a) {
		for (int i = 0;i < a.size;i++) {
			cout << i + 1 << ":";
			in >> a.mass[i];
		}
		return in;
	}
	Vector<t>& operator=(const Vector<t>& a) {
		for (int i = 0;i < a.size;i++) {
			mass[i] = a.mass[i];
		}
		return *this;
	}
	int operator()() {
		return size;
	}
	t operator[](int k) {
		return mass[k];
	}
	Vector<t> operator+(const Vector<t>&a) {
		Time aw(2, 67);
		Vector<t> tmp(a.size, aw);
		for (int i = 0;i < a.size;i++) {
			tmp.mass.pop_back();
		}
		for (int i = 0;i < a.size;i++) {
			tmp.mass.push_back(mass[i] + a.mass[i]);
		}
		return tmp;
	}
	void set_element(int index, t& a) {
		mass[index] = a;
	}
};
