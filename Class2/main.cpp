#include <iostream>
#include"book.h"
using namespace std;

book createbook() {
    string a, b;
    int c;
    cout << "Введите название книги:";
    cin >> a;
    cout << "Введите авторы книги:";
    cin >> b;
    cout << "Введите год издания:";
    cin >> c;
    book tmp(a, b, c);
    return tmp;
}
void printbook(book tmp) {
    tmp.show();
}
int main()
{
    setlocale(LC_ALL, "rus");
    book ex1;
    ex1.show();
    book ex2("Преступление и наказание", "Ф. М. Достоевский", 1866);
    ex2.show();
    book ex3 = ex2;
    ex3.show();
    return 0;

}

