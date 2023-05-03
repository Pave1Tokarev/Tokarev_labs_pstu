#pragma once
#include"Vector.h"
#include"Event.h"
class Dialog:public Vector
{
public:
	Dialog();
	void GetEvent(TEvent& event);
	void Execute();
	void HandleEvent(TEvent& event);
	void ClearEvent(TEvent& event);
	bool valid();
	void EndExec();
	~Dialog();
protected:
	int endstate;
	int number;
};

