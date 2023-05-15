#pragma once
#include<iostream>
using namespace std;
class Error {
private:
	string err;
public:
	Error(string s) {
		err = s;
	}
	void what() {
		cout << err << endl;
	}
};
