#include <iostream>
#include"Error.h"
#include"Vector.h"
int main()
{
    setlocale(LC_ALL, "rus");
    try {
        Vector tmp(5);
        cin >> tmp;
        cout << "Ввведите количество элементов для удаления: ";
        int n;
        cin >> n;
        tmp - n;
        cout << "Введите индекс элемента для вывода на экран: ";
        cin >> n;
        cout << tmp[n];
    }
    catch (Error err) {
        err.what();
    }
}
