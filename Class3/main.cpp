#include"Time.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Time a, b;
	cout << "Временной интервал a" << endl;
	cin >> a;
	cout << "Временной интервал b" << endl;
	cin >> b;
	if (a != b) {
		cout << "Временные интервалы не равны"<<endl;
	}
	else {
		cout << "Временные интервалы равны"<<endl;
	}
	cout << "Вычтем из первого интервала второй" << endl;
	Time c = a - b;
	cout << c;
}
