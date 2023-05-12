#pragma once
#include <iostream>
#include<set>
#include"Time.h"
using namespace std;
template<typename t>
class Vector {
private:
	multiset<t> st;
	int size;
public:
	Vector();
	Vector(int n);
	~Vector();
	void make_vector(int sz);
	void show();
	void addmin();
	void popkey(t key);
	void add_min_max();
};
template<typename t>
Vector<t>::Vector() {
	size = 0;
}
template <typename t>
Vector<t>::Vector(int n) {
	size = n;
}
template<typename t>
Vector<t>::~Vector() {

}
template <typename t>
void Vector<t>::make_vector(int sz) {
	t a;
	for (int i = 0;i < sz;i++) {
		cout << i + 1 << " : ";
		cin >> a;
		st.insert(a);
	}
}
template <typename t>
void Vector<t>::show() {
	for (auto& i : st) {
		cout << i << " ";
	}
	cout << endl;
}
template <typename t>
void Vector<t>::addmin() {
	st.insert(*st.begin());
}
template <typename t>
void Vector<t>::popkey(t key) {
	bool fl=false;
	multiset<t> ns;
	for (auto& i : st) {
		t tmp = i;
		if (tmp == key) {
			if (fl == false) {
				fl = true;
			}
			else {
				ns.insert(tmp);
			}
		}
		else {
			ns.insert(tmp);
		}
	}
	st = ns;
}
template<typename t>
void Vector<t>::add_min_max() {
	t min = *st.begin();
	t max = *st.begin();
	for (auto& i : st) {
		t tmp = i;
		int lft = tmp.get_minute() * 60 + tmp.get_second();
		int right = min.get_minute() * 60 + min.get_second();
		int rght = max.get_minute() * 60 + max.get_second();
		if (lft > rght) {
			max = i;
		}
		if (lft < right) {
			min = i;
		}
	}
	multiset<t> alf;
	for (auto& i : st) {
		t tmp = i;
		alf.insert(tmp + max + min);
	}
	st = alf;

}
void task3() {
	Vector<Time> vec;
	cout << "Введите количество элементов для добавления в вектор: ";
	int n;
	cin >> n;
	vec.make_vector(n);
	cout << "Добавим минимальный элемент в вектор" << endl;
	vec.addmin();
	vec.show();
	cout << "Удалим элемент из вектора по ключу" << endl;
	Time tmp;
	cout << "Введите ключ : "<<endl;
	cin >> tmp;
	vec.popkey(tmp);
	vec.show();
	cout << "Добавим к всем эллементам сумму мин и макс элементов" << endl;
	vec.add_min_max();
	vec.show();
}