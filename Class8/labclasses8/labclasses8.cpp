#include <iostream>
#include"Dialog.h"
#include"Employee.h"
#include"Event.h"
#include"Object.h"
#include"Person.h"
#include"Vector.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "m: Создать группу" << endl;
	cout << "+: Добавить элемент" << endl;
	cout << "-: Удалить элемент" << endl;
	cout << "s: Показать элементы группы" << endl;
	cout << "z: Вывести имя элемента" << endl;
	cout << "q: Завершить работу" << endl;
	Dialog D;
	D.Execute();
	return 0;
}

