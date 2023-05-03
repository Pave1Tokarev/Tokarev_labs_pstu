#pragma once
const int cnothing = 0;
const int cmsg = 100;
const int cadd = 1;
const int cdel = 2;
const int cget = 3;
const int cshow = 4;
const int cinf = 7;
const int cmake = 6;
const int cquit = 101;
struct  TEvent
{
	int what;
	int command;
};
