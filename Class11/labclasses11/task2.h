#pragma once
#include <iostream>
#include<list>
#include"Time.h"
#include<algorithm>
using namespace std;
typedef list<Time> lst2;
void show(lst2& a) {
	for (auto i = a.begin();i != a.end();i++) {
		cout << *i << " ";
	}
	cout << endl;
}
lst2 make_list(int count) {
	lst2 a;
	Time tmp;
	for (int i = 0;i < count;i++) {
		cout << i + 1 << " : ";
		cin >> tmp;
		a.push_back(tmp);
	}
	return a;
}
void find_min_and_add(lst2& a) {
	Time mn(100000,100000);
	for (auto i = a.begin();i != a.end();i++) {
		if (*i < mn) {
			mn = *i;
		}
	}
	a.push_back(mn);
}
void find_key(lst2& a, Time key) {
	auto j = a.begin();
	for (auto i = a.begin();i != a.end();i++) {
		if ((*i) == key) {
			break;
		}
		j++;
	}
	a.erase(j);
}
void add_min_max(lst2& a) {
	Time mn(100000, 100000);
	Time mx(0, 0);
	for (auto i = a.begin();i != a.end();i++) {
		if (*i < mn) {
			mn = *i;
		}
		if (*i > mx) {
			mx = *i;
		}
	}
	for (auto i = a.begin();i != a.end();i++) {
		(*i) = (*i) + (mx + mn);
	}
}
void task2() {
	list<Time> list1;
	int n;
	cout << "Введите размер списка : ";
	cin >> n;
	list1 = make_list(n);
	cout << "Найдём минимальный элемент и добавим его в конец" << endl;
	find_min_and_add(list1);
	show(list1);
	cout << "Найдём элемент с заданным ключём и удалим его" << endl;
	Time tmp;
	cout << "Введите ключ для удаления "<<endl;
	cin >> tmp;
	find_key(list1, tmp);
	show(list1);
	cout << "Добавим сумму максимального и минимального элемента списка к всем элементам" << endl;
	add_min_max(list1);
	show(list1);
}
