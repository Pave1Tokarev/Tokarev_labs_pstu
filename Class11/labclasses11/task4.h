#pragma once
#pragma once
#include <iostream>
#include<queue>
#include"Time.h"
#include<algorithm>
using namespace std;
typedef queue<Time> lst4;
void show(lst4 a) {
	int t = a.size();
	for (int i = 0;i < t;i++) {
		cout << a.front()<<" ";
		a.pop();
	}
	cout << endl;
}
lst4 make__list(int count) {
	lst4 a;
	Time tmp;
	for (int i = 0;i < count;i++) {
		cout << i + 1 << " : ";
		cin >> tmp;
		a.push(tmp);
	}
	return a;
}
void find_min_and_add(lst4& a) {
	Time mn(100000, 100000);
	int t = a.size();
	for (int i = 0;i<t;i++) {
		if (a.front() < mn) {
			mn = a.front();
		}
		a.push(a.front());
		a.pop();
	}
	a.push(mn);
}
void find_key(lst4& a, Time key) {
	lst4 b;
	while (!a.empty()) {
		Time tmp = a.front();
		if (tmp != key) {
			b.push(tmp);
		}
		a.pop();
	}
	a = b;
}
void add_min_max(lst4& a) {
	Time mn(100000, 100000);
	Time mx(0, 0);
	lst4 b=a;
	Time tmp;
	while (!b.empty()) {
		if (b.front() > mx) {
			mx =b.front();
		}
		if (b.front() < mn) {
			mn = b.front();
		}
		b.pop();
	}
	for (int i = 0;i<a.size();i++) {
		tmp = a.front();
		a.pop();
		a.push(tmp + mn + mx);
	}
}
void task4() {
	queue<Time> list4;
	int n;
	cout << "Введите размер очереди : ";
	cin >> n;
	list4 = make__list(n);
	cout << "Найдём минимальный элемент и добавим его в конец" << endl;
	find_min_and_add(list4);
	show(list4);
	cout << "Найдём элемент с заданным ключём и удалим его" << endl;
	Time tmp;
	cout << "Введите ключ для удаления : ";
	cin >> tmp;
	find_key(list4, tmp);
	show(list4);
	cout << "Добавим сумму максимального и минимального элемента очереди к всем элементам" << endl;
	add_min_max(list4);
	show(list4);
}
