#pragma once
#ifndef PESEL_H
#define PESEL_H
#include <iostream>

using namespace std;

class PESEL
{
private:
	int number[11];
	int day, month, year;
public: 
	PESEL();
	PESEL(int*);
	PESEL(const string&);
	PESEL(int, int, int);
	friend ostream& operator<<(ostream&, const PESEL&);
	int * getNumber();
	string toString();
	string getBirthDate();
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	friend bool operator> (const PESEL &p1, const PESEL &p2);
};
#endif