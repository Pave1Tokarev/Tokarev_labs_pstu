#pragma once
#include<iostream>
using namespace std;
class Error {
public:
	virtual void what() {
	};
};
class OutOfIndex :public Error {
protected:
	string msg;
public:
	OutOfIndex() {
		msg = "������ ���������";
	}
	virtual void what() {
		cout << msg << endl;
	}

};
class SizeError :public Error {
protected:
	string msg;
public:
	SizeError() {
		msg = "������ � ������� �������";
	}
	virtual void what() {
		cout << msg << endl;
	}
};
class OverSizeError :public Error {
protected:
	string msg;
public:
	OverSizeError() {
		msg = "���������� ������ ������� ��������";
	}
	virtual void what() {
		cout << msg << endl;
	}
};
class EmptyVector :public SizeError {
protected:
	string msg;
public:
	EmptyVector() {
		msg = "��������  �� ������� ������� ����������";
	}
	virtual void what() {
		cout << msg << endl;
	}
};
class IndexLowerThanZero : public OutOfIndex {
protected:
	string msg;
public:
	IndexLowerThanZero() {
		msg = "������ ������ ����";
	}
	virtual void what() {
		cout << msg << endl;
	}
};
class IndexOutOfSize : public OutOfIndex {
protected:
	string msg;
public:
	IndexOutOfSize() {
		msg = "������ ������ �������� �������";
	}
	virtual void what() {
		cout << msg << endl;
	}
};