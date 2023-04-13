#include<iostream>
#include"iterator.h"
#include"vector.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	vector a(10);
	a.fillrandom(a());
	cout << "Заполним вектор случайными числами" <<endl;
	cout << a<<endl;
	cout <<"Первый элемент: " << *(a.first())<<endl;
	cout << "Последний элемент: " << *(a.last()) << endl;
	cout << "Выедите вектор b из 10 элементов" << endl;
	vector b(10);
	cin >> b;
	cout << "6 элемент: " <<b[5] << endl;
	cout << "Выведем вектор с помощью итератора" << endl;
	Iterator iter = b.first();
	for (int i = 0;i < 10;i++) {
		cout << *(iter)<<" ";
		iter = iter + 1;
	}
	cout <<endl<< "Сложим векторы a и b" << endl;
	vector c = a + b;
	cout << c;
}
