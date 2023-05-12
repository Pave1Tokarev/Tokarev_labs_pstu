#include<iostream>
#include<set>
#include"Time.h"
using namespace std;
typedef set<Time> set2;
void makeset(int n, set2& a) {
	Time tmp;
	for (int i = 0;i < n;i++) {
		cout << i + 1 << " : ";
		cin >> tmp;
		a.insert(tmp);
	}
}
void show(set2& a) {
	for (auto i = a.begin();i != a.end();i++) {
		cout << *i << " ";
	}
	cout << endl;
}
void findmin(set2& a) {
	Time min(100000, 10000);
	for (auto& i : a) {
		Time tmp = i;
		int lft = tmp.get_minute() * 60 + tmp.get_second();
		int right = min.get_minute() * 60 + min.get_second();
		if (lft < right) {
			min = tmp;
		}
	}
	a.insert(min);
}
void findkey(set2& a, Time key) {
	a.erase(key);
}
void add_min_max(set2& a) {
	Time min = *a.begin();
	Time max = *a.begin();
	for (auto& i : a) {
		Time tmp=i;
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
	set2 tmp1;
	for (auto& i : a) {
		Time tmp = i;
		tmp1.insert(tmp + max + min);
	}
	a = tmp1;
}
void task2() {
	set<Time> set2;
	cout << "Введите количество элементов для добавления в множество: ";
	int n;
	cin >> n;
	makeset(n, set2);
	cout << "Добавим минимальный элемент в множество" << endl;
	findmin(set2);
	show(set2);
	cout << "Удалим элемент из множества по ключу" << endl;
	Time tmp;
	cout << "Введите ключ : ";
	cin >> tmp;
	findkey(set2, tmp);
	show(set2);
	cout << "Добавим к всем эллементам сумму мин и макс элементов" << endl;
	add_min_max(set2);
	show(set2);
}