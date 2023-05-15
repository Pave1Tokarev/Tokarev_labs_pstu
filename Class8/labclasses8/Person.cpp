#include "Person.h"
Person::Person() {
	name = "";
	age = 0;
}
Person::Person(int a, string b) {
	name = b;
	age = a;
}
Person::Person(const Person& a) {
	name = a.name;
	age = a.age;
}
Person::~Person() {

}
void Person::show() {
	cout << "���: " << name << endl;
	cout << "������: " << age << endl;
}
Person& Person::operator=(const Person& a) {
	name = a.name;
	age = a.age;
	return *this;
}
void Person::set_name(string a) {
	name = a;
}
void Person::set_age(int a) {
	age = a;
}
int Person::get_age() {
	return age;
}
string Person::get_name() {
	return name;
}
istream& operator>>(istream& in, Person& a) {
	cout << "���: ";
	in >> a.name;
	cout << "�������: ";
	in >> a.age;
	return in;
}
ostream& operator<<(ostream& out, const Person& a) {
	out << "���: " << a.name << endl;
	out << "�������: " << a.age << endl;
	return out;
}