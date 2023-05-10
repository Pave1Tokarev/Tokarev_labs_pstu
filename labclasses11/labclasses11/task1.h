#pragma once
#include <iostream>
#include<list>
#include"Time.h"
#include<algorithm>
using namespace std;
typedef list<float> lst;
void show(lst& a) {
	for (auto i = a.begin();i != a.end();i++) {
		cout << *i << " ";
	}
	cout << endl;
}
lst makelist(int count) {
	lst a;
	float tmp;
	for (int i = 0;i < count;i++) {
		cout << i + 1 << " : ";
		cin >> tmp;
		a.push_back(tmp);
	}
	return a;
}
void find_min_and_add(lst& a) {
	float mn = 100000000;
	for (auto i = a.begin();i !=a.end();i++) {
		if (*i < mn) {
			mn = *i;
		}
	}
	a.push_back(mn);
}
void find_key(lst& a,float key) {
	auto j = a.begin();
	for (auto i = a.begin();i != a.end();i++) {
		if ((*i) == key) {
			break;
		}
		j++;
	}
	a.erase(j);
}
void add_min_max(lst& a) {
	float mn = *std::min_element(a.begin(), a.end());
	float mx = *std::max_element(a.begin(), a.end());
	for (auto i = a.begin();i != a.end();i++) {
		*i += (mn + mx);
	}
}
void task1() {
	list<float> list1;
	int n;
	cout << "Введите размер списка : ";
	cin >> n;
	list1=makelist(n);
	cout << "Найдём минимальный элемент и добавим его в конец" << endl;
	find_min_and_add(list1);
	show(list1);
	cout << "Найдём элемент с заданным ключём и удалим его" << endl;
	float tmp;
	cout << "Введите ключ для удаления : ";
	cin >> tmp;
	find_key(list1, tmp);
	show(list1);
	cout << "Добавим сумму максимального и минимального элемента списка к всем элементам" << endl;
	add_min_max(list1);
	show(list1);
}
