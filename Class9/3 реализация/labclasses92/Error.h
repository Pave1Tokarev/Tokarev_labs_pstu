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
		msg = "Ошибка индесации";
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
		msg = "Ошибка в размере вектора";
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
		msg = "Допустимый размер вектора превышен";
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
		msg = "Удаление  из пустого вектора невозможно";
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
		msg = "Индекс меньше нуля";
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
		msg = "Индекс больше текущего размера";
	}
	virtual void what() {
		cout << msg << endl;
	}
};