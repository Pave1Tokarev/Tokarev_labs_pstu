#include<iostream>
#include"Money.h"
using namespace std;
void Money::init(int tmp1, int tmp2) {
	first = tmp1;
	second= tmp2;
}
void Money::read() {
	while (first != 1 && first != 2 && first != 5 && first != 10 && first != 50 && first != 100 && first != 500 && first != 1000 && first != 5000) {
		cout << "������� ������� ������: ";
		cin >> first;
	}
	cout << "������� ���������� �����: ";
	cin >> second;

}
void Money::show() {
	cout << "������� �����: " << first << endl;
	cout << "���������� ����� :" << second << endl;
}
int Money::summa() {
	return (first * second);
}
struct Point {
	int x;
	int y;
};
