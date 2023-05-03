#include "Dialog.h"
#include"Person.h"
#include"Employee.h"
#include <iostream>
using namespace std;
void Dialog::Execute() {
	TEvent event;
	while (valid()) {
		endstate = 0;
		GetEvent(event);
		HandleEvent(event);
	}
}
bool Dialog::valid(){
	return (endstate == 0);
}
void Dialog::HandleEvent(TEvent& event) {
	if (event.what == cmsg) {
		int a;
		switch (event.command)
		{
		case cmake:
			cout << "¬ведите размер группы: " << endl;
			cin >> a;
			beg = new Object * [a];
			current = 0;
			size = a;
			ClearEvent(event);
			break;
		case cadd:
			Object* ptm;
			cout << "1.Person" << endl;
			cout << "2.Employee" << endl;
			cin >> a;
			if (a == 1) {
				Person *sw=new Person;
				cin >> *sw;
				ptm = sw;
				add(ptm);

			}
			else {
				Employee *sw=new Employee;
				cin >> *sw;
				ptm = sw;
				add(ptm);
			}
			ClearEvent(event);
			break;
		case cdel:
			del();
			ClearEvent(event);
			break;
		case cshow:
			show();
			ClearEvent(event);
			break;
		case cinf:
			cout << "¬ведите номер элемента" << endl;
			int k;
			cin >> k;
			if (k < current+1) {
				getname(k-1);
			}
			ClearEvent(event);
			break;
		case cquit:
			EndExec();
			break;
		}
	}
}
void Dialog::GetEvent(TEvent& event) {
	string var = "m+-szq";
	string s;
	cin >> s;
	char num = s[0];
	if (var.find(num)>=0) {
		event.what = cmsg;
		switch (num) {
		case 'm':
			event.command = cmake;
			break;
		case '+':
			event.command = cadd;
			break;
		case '-':
			event.command = cdel;
			break;
		case 's':
			event.command = cshow;
			break;
		case 'z':
			event.command = cinf;
			break;
		case 'q':
			event.command = cquit;
			break;
		}
	}
	else {
		event.what = cnothing;
	}
}
void Dialog::ClearEvent(TEvent& event) {
	event.what = cnothing;
}
void Dialog::EndExec() {
	endstate = 1;
}
Dialog::Dialog() {
	endstate = 0;
	number = 0;
}
Dialog::~Dialog() {

}