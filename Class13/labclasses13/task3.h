#pragma once
#include<algorithm>
#include<queue>
#include"Time.h"
#include<functional>
#include<vector>
#include<list>
#include<set>
using namespace std;
void make_list(multiset<int>& lst, int n) {
	int tmp;
	for (int i = 0;i < n;i++) {
		cout << i + 1 << " : ";
		cin >> tmp;
		lst.insert(tmp);
	}
}
bool m_equal(Time& a, Time& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}
void sshow(multiset<int>& lst) {
	vector<int> Copy;
	int q;
	size_t lst_sz = lst.size();
	for (auto& i : lst) {
		cout << i << " ";
	}
	cout << endl;

}
void find_time(multiset<int> lst, int& t) {
	vector<int> Copy;
	int q;
	for (auto& i : lst) {
		Copy.push_back(i);
	}
	for_each(Copy.begin(), Copy.end(), [&t](int k) {if (k == t) { cout << "Элемент найден" << endl; }});
}
void addmin(multiset<int>& lst) {
	int mn = 100000;
	for (auto& i : lst) {
		mn = min(mn, i);

	}
	lst.insert(mn);
}
void pop_key(multiset<int>& lst, int& key) {
	vector<int> temp;
	for (auto& i : lst) {
		temp.push_back(i);
	}
	multiset<int> pt;
	bool fl = false;
	for_each(temp.begin(), temp.end(), [&fl, &key, &pt](int& p) {
		if (fl == false && p == key) {
			fl = true;
		}
		else { pt.insert(p); }});
	lst = pt;
}
void add_min_max(multiset<int>& lst) {
	multiset<int> ns;
	vector<int> Copy;
	int q;
	size_t lst_sz = lst.size();
	for (auto& i : lst) {
		Copy.push_back(i);
	}
	int min = 1000000;
	int max = 0;
	for_each(Copy.begin(), Copy.end(), [&min, &max](int& t) {int g = t;if (max < g) { max = g; }if (min > g) { min = g; }});
	for_each(Copy.begin(), Copy.end(), [&min, &max](int& t) {t = t + min + max;});
	for (auto i = Copy.begin(); i != Copy.end(); i++)
		ns.insert(*i);
	lst = ns;
}
void task3() {
	multiset<int> new_list;
	cout << "Введите размер очереди : ";
	int n;
	cin >> n;
	make_list(new_list, n);
	sshow(new_list);
	cout << "Добавим в конец минимальный элемент" << endl;
	addmin(new_list);
	sshow(new_list);
	cout << "Проверим элемент на вхождение : " << endl;
	int a;
	cin >> a;
	find_time(new_list, a);
	cout << "Удалим элемент с заданным ключём" << endl;
	cout << "Ключ:" << endl;
	cin >> a;
	pop_key(new_list, a);
	sshow(new_list);
	cout << "Добавим к всем элементам очереди min+max" << endl;
	add_min_max(new_list);
	sshow(new_list);
}