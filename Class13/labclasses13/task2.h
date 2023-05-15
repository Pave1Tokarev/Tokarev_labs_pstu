#pragma once
#include<algorithm>
#include<queue>
#include"Time.h"
#include<functional>
#include<vector>
#include<list>
using namespace std;
void make_list(queue<Time>& lst, int n) {
	Time tmp;
	for (int i = 0;i < n;i++) {
		cin >> tmp;
		lst.push(tmp);
	}
}
bool q_equal(Time& a, Time& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}
void qshow(queue<Time>& lst) {
	vector<Time> Copy;
	Time q;
	size_t lst_sz = lst.size();
	for (int i = 0;i < lst_sz;i++) {
		q = lst.front();
		cout << q<<" ";
		Copy.push_back(q);
		lst.pop();
	}
	int k = 0;
	for (int t = 0;t < Copy.size();t++) {
		lst.push(Copy[k]);
		k++;
	}
	cout << endl;
	
}
void find_time(queue<Time> lst, Time& t) {
	vector<Time> Copy;
	Time q;
	size_t lst_sz = lst.size();
	for (int i = 0;i < lst_sz;i++) {
		q = lst.front();
		Copy.push_back(q);
		lst.pop();
	}
	auto it = find_if(Copy.begin(), Copy.end(), bind(eq, placeholders::_1, t));
	if (it == Copy.end())
	{
		cout << "Элемент не найден" << endl;
		return;
	}
	for (auto i = Copy.begin(); i != Copy.end(); ++i)
		if (i == it)
			cout << "Элемент найден - " << *i << endl;
}
void addmin(queue<Time>& lst) {
	vector<Time> Copy;
	Time q;
	size_t lst_sz = lst.size();
	for (int i = 0;i < lst_sz;i++) {
		q = lst.front();
		Copy.push_back(q);
		lst.pop();
	}
	Time tmp(100000, 10000);
	for_each(Copy.begin(), Copy.end(), [&tmp](Time& t) {if (tmp > t) { tmp = t; }});
	for_each(Copy.begin(), Copy.end(), [&tmp, &lst](Time& t) {lst.push(t);});
	lst.push(tmp);
}
void pop_key(queue<Time>& lst, Time key) {
	vector<Time> temp;
	size_t q_size=lst.size();
	for (int i = 0; i <q_size; i++)
	{
		temp.push_back(lst.front());
		lst.pop();
	}
	bool fl = false;
	for_each(temp.begin(), temp.end(), [&fl, &key, &lst](Time& p) {
		if (fl == false && p == key) {
			fl = true;
		}
		else { lst.push(p); }});
	
}
void add_min_max(queue<Time>& lst) {

	vector<Time> Copy;
	Time q;
	size_t lst_sz = lst.size();
	for (int i = 0;i < lst_sz;i++) {
		q = lst.front();
		Copy.push_back(q);
		lst.pop();
	}
	Time min(100000, 10000);
	Time max(0, 0);
	for_each(Copy.begin(), Copy.end(), [&min, &max](Time& t) {if (max < t) { max = t; }if (min > t) { min = t; }});
	for_each(Copy.begin(), Copy.end(), [&min, &max](Time& t) {t = t + min + max;});
	for (auto i = Copy.begin(); i != Copy.end(); i++)
		lst.push(*i);
}
void task2() {
	queue<Time> new_list;
	cout << "Введите размер очереди : ";
	int n;
	cin >> n;
	make_list(new_list, n);
	cout << "Добавим в конец минимальный элемент" << endl;
	addmin(new_list);
	qshow(new_list);
	cout << "Проверим элемент на вхождение : " << endl;
	Time a;
	cin >> a;
	find_time(new_list, a);
	cout << "Удалим элемент с заданным ключём" << endl;
	cout << "Ключ:" << endl;
	cin >> a;
	pop_key(new_list, a);
	qshow(new_list);
	cout << "Добавим к всем элементам очереди min+max" << endl;
	add_min_max(new_list);
	qshow(new_list);
	cout << "Отсортируем очередь" << endl;
	qshow(new_list);


}