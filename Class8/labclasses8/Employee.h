#pragma once
#include "Person.h"
using namespace std;
class Employee:
	public Person
{
protected:
	float salary;
	string job;
public:
	Employee(void);
	~Employee(void);
	void show();
	Employee(int, string, float, string);
	Employee(const Employee&);
	float get_salary();
	string get_job();
	string get_name();
	void set_salary(float a);
	void set_job(string a);
	Employee& operator=(const Employee&);
	friend istream& operator>>(istream& in, Employee& a);
	friend ostream& operator<<(ostream& out, const Employee& a);
};

