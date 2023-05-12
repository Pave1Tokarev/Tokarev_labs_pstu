#include<iostream>
#include<set>
#include<queue>
using namespace std;
typedef set<float> set1;
void makeset(int n,set1&a) {
	float tmp;
	for (int i = 0;i < n;i++) {
		cout << i + 1 << " : ";
		cin >> tmp;
		a.insert(tmp);
	}
}
void show(set1& a) {
	for (auto i = a.begin();i != a.end();i++) {
		cout << *i << " ";
	}
	cout << endl;
}
void findmin(set1&a){
	float min = 100000.0;
	for(auto i=a.begin();i!=a.end();i++){
		if (*i < min) {
			min = *i;
		}
	}
	a.insert(min);
}
void findkey(set1 & a,float key) {
	a.erase(key);
}
void add_min_max(set1& a) {
	float min = *a.begin();
	float max = *a.begin();
	for (auto& i : a) {
		if (i > max) {
			max = i;
		}
		if (i < min) {
			min = i;
		}
	}
	set1 tmp;
	for (auto& i : a) {
		tmp.insert(i + max + min);
	}
	a = tmp;
}
void task1() {
	set<float> set2;
	cout << "������� ���������� ��������� ��� ���������� � ���������: ";
	int n;
	cin >> n;
	makeset(n, set2);
	cout << "������� ����������� ������� � ���������" << endl;
	findmin(set2);
	show(set2);
	cout << "������ ������� �� ��������� �� �����" << endl;
	float tmp;
	cout << "������� ���� : ";
	cin >> tmp;
	findkey(set2,tmp);
	show(set2);
	cout << "������� � ���� ���������� ����� ��� � ���� ���������" << endl;
	add_min_max(set2);
	show(set2);
}