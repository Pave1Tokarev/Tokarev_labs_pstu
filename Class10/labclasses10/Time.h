#pragma once
#include <iostream>
#include<fstream>
using namespace std;
class Time {
    int min, sec;
public:
    Time() {
        min = 0;
        sec = 0;
    }
    Time(int tmp1, int tmp2) {
        min = tmp1;
        sec = tmp2;
    }
    Time(const Time& t) {
        min = t.min;
        sec = t.sec;
    }
    ~Time() {};
    int getminute() {
        return min;
    }
    int getsecond() {
        return sec;
    }
    void setminute(int tmp) {
        min = tmp;
    }
    void setsecond(int tmp) {
        sec = tmp;
    }
    Time& operator=(const Time&);
    Time operator-(const Time&);
    bool operator!=(const Time&);
    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
    friend fstream& operator>>(fstream& fin, Time& t);
    friend fstream& operator<<(fstream& fout, const Time& t);
};