#pragma once
#include<iostream>
#include<queue>
#include"Time.h"
using namespace std;
template <typename t>
class new_vector {
private:
	queue<t> nv;
	int size;
public:
	new_vector();
	new_vector(int n);
	~new_vector();
	void make_vector(int sz);
	void show();
	void add_min();
	void delete_key(t key);
	void add_min_max();
};
template <typename t>
new_vector<t>::new_vector() {

}
template<typename t>
new_vector<t>::new_vector(int nt) {
	t a;
	for (int i = 0;i < nt;i++) {
		cin >> a;
		nv.push(a);
	}
}
template <typename t>
new_vector<t>::~new_vector() {

}
template <typename t>
void new_vector<t>::make_vector(int sz) {
	t a;
	size = sz;
	for (int i = 0;i < sz;i++) {
		cout << i + 1 << " : ";
		cin >> a;
		nv.push(a);
	}
}
template<typename t>
void new_vector<t>::show() {
	int k= nv.size();
	for (int i = 0;i < k;i++) {
		cout << nv.front() << endl;
		nv.push(nv.front());
		nv.pop();
	}
	cout << endl;
}
template <typename t>
void new_vector<t>::add_min() {
	queue<t> b=nv;
	t min(100000,100000);
	while (!b.empty()) {
		if (b.front() < min) {
			min = b.front();
		}
		b.pop();
	}
	nv.push(min);
}
template<typename t>
void new_vector<t>::delete_key(t key) {
	int j = nv.size();
	for (int i = 0;i < j;i++) {
		if (nv.front() != key) {
			nv.push(nv.front());
		}
		nv.pop();
	}
}
template<typename t>
void new_vector<t>::add_min_max() {
	t min(10000, 10000);
	t max(0, 0);
	int j = nv.size();
	for (int i = 0;i < j;i++) {
		if (nv.front() < min) {
			min = nv.front();
		}
		if (nv.front() > max) {
			max = nv.front();
		}
		nv.push(nv.front());
		nv.pop();
	}
	for (int i = 0;i < j;i++) {
		nv.push(nv.front() + max + min);
		nv.pop();
	}
}
typedef new_vector<Time> nw1;
void task5() {
	nw1 tmp;
	int n;
	cout << "Введите размер вектора : ";
	cin >> n;
	tmp.make_vector(n);
	cout << "Найдём минимальный элемент и добавим его в конец" << endl;
	tmp.add_min();
	tmp.show();
	cout << "Найдём элемент с заданным ключём и удалим его" << endl;
	Time ky;
	cout << "Введите ключ для удаления " << endl;
	cin >> ky;
	tmp.delete_key(ky);
	tmp.show();
	cout << "Добавим сумму максимального и минимального элемента вектора к всем элементам" << endl;
	tmp.add_min_max();
	tmp.show();
}
