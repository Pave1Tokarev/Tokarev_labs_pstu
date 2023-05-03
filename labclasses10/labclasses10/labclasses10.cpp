#include <iostream>
#include"Filestream.h"
#include"Time.h"
using namespace std;
void menu() {
    int sw=-1;
    int k;
    Time sample;
    char fname[30];
    while (sw != 0) {
        cout << "1.Создать файл" << endl;
        cout << "2.Вывести элементы файла на экран" << endl;
        cout << "3.Удалить элементы с заданным значением" << endl;
        cout << "4.Добавить К элементов в начало файла" << endl;
        cout << "5.Уменьшить время элементов с заданным значение на 1 минуту 30 секунд" << endl;
        cout << "6.Выход из прграммы" << endl;
        cin >> sw;
        switch (sw) {
        case 1:
            cout << "Введите имя файла:";
            cin >> fname;
            CreateFile(fname);
            break;
        case 2:
            PrintFile(fname);
            break;
        case 3:
            cout << " Введите значения элементов для удаления"<<endl;
            cin >> sample;
            DeleteFromFile(fname, sample);
            break;
        case 4:
            cout << "Введите количество элементов для добавления: ";
            cin >> k;
            AddKElelement(fname, k);
            break;
        case 5:
            cin >> sample;
            ReduceTime(fname, sample);
            break;
        default:
            sw = 0;
            break;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    menu();
}