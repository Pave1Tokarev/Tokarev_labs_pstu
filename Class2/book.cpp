#include<iostream>
#include"book.h"
using namespace std;
book::book() {
    name = "";
    author = "";
    year = 0;
    cout << "������ ����������� ��� ����������" << endl;
}
book::book(string nam, string autho, int yer) {
    name = nam;
    author = autho;
    year = yer;
    cout << "������ ����������� � �����������" << endl;
}
book::book(const book& t) {
    this->name = t.name;
    this->author = t.author;
    this->year = t.year;
    cout << "������ ����������� ������������" << endl;
}
book::~book() {
    cout << "������ ����������" << endl;
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
    cout << "��������:" << name << endl;
    cout << "�����:" << author << endl;
    cout << "���:" << year << endl;

}