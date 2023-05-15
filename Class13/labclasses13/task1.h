#pragma once
#include<algorithm>
#include<list>
#include"Time.h"
#include<functional>
using namespace std;
bool fnd = false;
void make_list(list<Time>& lst,int n) {
	Time tmp;
	for (int i = 0;i < n;i++) {
		cin >> tmp;
		lst.push_back(tmp);
	}
}
bool eq(Time& a, Time& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}
void show(list<Time>& lst) {
	for_each(lst.begin(), lst.end(), [](const Time& t) {
		cout << t << " ";
		});
	cout << endl;
}
void find_time(list<Time> lst, Time& t) {
	auto it = find_if(lst.begin(), lst.end(), bind(eq, placeholders::_1, t));
	if (it == lst.end())
	{
		cout << "Элемент не найден" << endl;
		return;
	}
	for (auto i = lst.begin(); i != lst.end(); ++i)
		if (i == it)
			cout << "Элемент найден - " << *i<<endl;
}
void addmin(list<Time> &lst) {
	Time tmp(100000,10000);
	for_each(lst.begin(), lst.end(), [&tmp](Time& t) {if (tmp > t) { tmp = t; }});
	lst.push_back(tmp);
}

void pop_key(list<Time> &lst, Time key) {
	auto j=remove_if(lst.begin(), lst.end(), [&key](Time& t) {return t == key;});
	lst.erase(j, lst.end());
}
void add_min_max(list<Time> &lst) {
	Time min(100000, 10000),max(0,0);
	for_each(lst.begin(), lst.end(), [&min](Time& t) {if (min > t) { min = t; }});
	for_each(lst.begin(), lst.end(), [&max](Time& t) {if (max<t) { max = t; }});
	list <Time> lsttmp;
	for_each(lst.begin(), lst.end(), [&lsttmp,&min,&max](Time& t) {lsttmp.push_back(t+min+max);});
	lst = lsttmp;
}
void task1() {
	list<Time> new_list;
	cout << "Введите размер списка : ";
	int n;
	cin >>n;
	make_list(new_list, n);
	cout << "Добавим в конец минимальный элемент" << endl;
	addmin(new_list);
	show(new_list);
	cout << "Проверим элемент на вхождение : " << endl;
	Time a;
	cin >> a;
	find_time(new_list,a);
	cout << "Удалим элемент с заданным ключём" << endl;
	cout << "Ключ:"<<endl;
	cin >> a;
	pop_key(new_list, a);
	show(new_list);
	cout << "Добавим к всем элементам списка min+max" << endl;
	add_min_max(new_list);
	show(new_list);
	cout << "Отсортируем список" << endl;
	new_list.sort(mem_fun_ref(&Time::operator<));
	show(new_list);


}