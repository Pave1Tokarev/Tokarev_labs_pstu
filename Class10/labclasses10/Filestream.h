#pragma once
#include <iostream>
#include"Time.h"
using namespace std;
	void CreateFile(const char* filename) {
		fstream fout(filename, ios::out | ios::trunc);
		if (!fout) {
			cout << "Не удалось открыть файл" << endl;
		}
		else {
			Time tmp;
			int size;
			cout << "Введите число объектов для записи: ";
			cin >> size;
			for (int i = 0;i < size;i++) {
				cin >> tmp;
				fout << tmp;
			}
			fout.close();
		}
	}
	void PrintFile(const char* filename) {
		fstream fin(filename, ios::in);
		if (!fin) {
			cout << "Не удалось открыть файл" << endl;
		}
		else {
			Time tmp;
			while (fin >> tmp) {
				cout << tmp << endl;
			}
		}
		fin.close();
	}
	void DeleteFromFile(const char* filename, Time&t) {
		fstream temp("temp", ios::out);
		fstream fin(filename, ios::in);
		Time tm;
		while (fin >> tm) {
			if (fin.eof()) {
				break;
			}
			if ((t.getminute() != tm.getminute()) || (t.getsecond() != tm.getsecond())) {
				temp << tm;
			}
		}
		temp.close();
		fin.close();
		remove(filename);
		rename("temp", filename);
	}
	void AddKElelement(const char* filename, int k) {
		Time tm;
		fstream temp("temp", ios::out);
		fstream fout(filename, ios::in);
		for (int i = 0;i < k;i++) {
			cin >> tm;
			temp << tm;
		}
		while (fout >> tm) {
			if (fout.eof()) {
				break;
			}
			temp << tm;
		}
		fout.close();
		temp.close();
		remove(filename);
		rename("temp", filename);
	}
	void ReduceTime(const char* filename, Time& t) {
		Time tm;
		Time rq;
		rq.setminute(1);
		rq.setsecond(30);
		fstream temp("temp", ios::out);
		fstream fout(filename, ios::in);
		int min30 = t.getminute() * 60 + t.getsecond();
		while (fout >> tm) {
			int newtime = tm.getminute() * 60 + tm.getsecond();
			if (tm.getminute() == t.getminute() && tm.getsecond() == t.getsecond() && tm.getminute() * 60 + tm.getsecond() >= 90) {
				tm = tm - rq;
				temp << tm;
			}
			else {
				temp << tm;
			}

		}
		fout.close();
		temp.close();
		remove(filename);
		rename("temp", filename);
	}

