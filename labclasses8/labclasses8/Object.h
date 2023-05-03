#pragma once
#include<iostream>
using namespace std;
class Object
{
public:
	Object();
	virtual ~Object(void);
	virtual void show() = 0;
	virtual string get_name() = 0;
};

