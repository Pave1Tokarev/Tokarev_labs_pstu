#pragma once
#include"Time.h"
#include<vector>
template <typename t>
class Vector {
private:
	int  size;
	vector<t> mass;
public:
	Vector() {
		size = 0;

	}
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
	Vector<t> operator+(const Vector<t>& a) {
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
	void make_vector(int sz);
	void show();
	void add_min();
	void delete_key(t key);
	void add_min_max();
};
template <typename t>
void Vector<t>::make_vector(int sz) {
	t a;
	size = sz;
	for (int i = 0;i < sz;i++) {
		cin >> a;
		mass.push_back(a);
	}
}
template <typename t>
void Vector<t>::show() {
	for (auto i = mass.begin();i != mass.end();i++) {
		cout << *i << " ";
	}
	cout << endl;
}
template <typename t>
void Vector<t>::add_min() {
	t min(100000, 100000);
	for (auto i = mass.begin();i != mass.end();i++) {
		if ((*i) < min) {
			min = *i;
		}
	}
	mass.push_back(min);
}
template <typename t>
void Vector<t>::delete_key(t key) {
	int j = 0;
	bool fl = false;
	vector <t> b;
	for (auto i = mass.begin();i != mass.end();i++) {
		if (*i == key) {
			if (fl == false) {
				fl = true;
			}
			else{
				b.push_back(*i);
			}
		}
		else {
			b.push_back(*i);
		}

	}
			mass = b;

}
template <typename t>
void Vector<t>::add_min_max() {
	t min(10000, 10000);
	t max(0, 0);
	for (auto i = mass.begin();i != mass.end();i++) {
		if ((*i) > max) {
			max = *i;
		}
		if ((*i) < min) {
			min = *i;
		}
	}
	mass.push_back(min + max);
}
typedef Vector<Time> lst3;
void task3() {
	lst3 tmp;
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
