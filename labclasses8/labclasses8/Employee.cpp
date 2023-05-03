#include "Employee.h"
Employee::Employee():Person() {
	salary = 0.0;
	job = "";
}
Employee::Employee(int a, string b, float c, string d) :Person(a, b) {
	salary = c;
	job = d;
}
Employee::Employee(const Employee& a) {
	age = a.age;
	name = a.name;
	salary = a.salary;
	job = a.job;
}
Employee::~Employee() {

}
void Employee::show() {
	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
	cout << "Зарплата: " << salary << endl;
	cout << "Должность: " << job << endl;
}
float Employee::get_salary() {
	return salary;
}
string Employee::get_job() {
	return job;
}
void Employee::set_job(string a) {
	job = a;
}
void Employee::set_salary(float a) {
	salary = a;
}
Employee& Employee::operator=(const Employee& a) {
	age = a.age;
	name = a.name;
	job = a.job;
	salary = a.salary;
	return *this;
}
istream& operator>>(istream & in,  Employee & a) {
	cout << "Имя: ";
	in >> a.name;
	cout << "Возраст: ";
	in >> a.age;
	cout << "Зарплата: ";
	in >> a.salary;
	cout << "Должность: ";
	in >> a.job;
	return in;
}
ostream& operator<<(ostream& out, const Employee& a) {
	out << "Имя: " << a.name << endl;
	out << "Возраст: " << a.age << endl;
	out << "Зарплата: " << a.salary << endl;
	out << "Должность: " << a.job << endl;
	return out;
}
string Employee::get_name() {
	return name;
}