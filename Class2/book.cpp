#include<iostream>
#include"book.h"
using namespace std;
book::book() {
    name = "";
    author = "";
    year = 0;
    cout << "Вызван конструктор без параметров" << endl;
}
book::book(string nam, string autho, int yer) {
    name = nam;
    author = autho;
    year = yer;
    cout << "Вызван конструктор с параметрами" << endl;
}
book::book(const book& t) {
    this->name = t.name;
    this->author = t.author;
    this->year = t.year;
    cout << "Вызван конструктор копированием" << endl;
}
book::~book() {
    cout << "Вызван деструктор" << endl;
};
string book::getname() {
    return name;
}
string book::getauthor() {
    return author;
}
int book::getyear() {
    return year;
}
void book::setname(string tmp) {
    name = tmp;
}
void book::setauthor(string tmp) {
    author = tmp;
}
void book::setyear(int tmp) {
    year = tmp;
}
void book::show() {
    cout << "Название:" << name << endl;
    cout << "Автор:" << author << endl;
    cout << "Год:" << year << endl;

}