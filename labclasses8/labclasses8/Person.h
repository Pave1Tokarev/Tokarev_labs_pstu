#pragma once
#include <iostream>
#include"Object.h"
using namespace std;
class Person:public Object
{
protected:
	string name;
	int age;
public:
	Person(void);
	Person(int, string);
	Person(const Person&);
	virtual ~Person(void);
	void show();
	Person& operator=(const Person&);
	void set_name(string a);
	void set_age(int a);
	int get_age();
	string get_name();
	friend istream& operator>>(istream& in, Person& a);
	friend ostream& operator<<(ostream& out, const Person& a);
};

