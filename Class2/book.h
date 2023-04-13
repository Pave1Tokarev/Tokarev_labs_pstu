#pragma once
#include <iostream>
using namespace std;
class book {
    string name;
    string author;
    int year;
public:
    book();
    book(string, string, int);
    book(const book&);
    ~book();
    string getname();
    string getauthor();
    int getyear();
    void setname(string);
    void setauthor(string);
    void setyear(int);
    void show();
};