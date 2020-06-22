#include "pch.h"
#include "PESEL.h"
#include <iostream>
#include <string>
#include "Algorithm.h"

using namespace std;

PESEL::PESEL() {
	Algorithm alg;
	for (int i = 0; i < 11; i++) number[i] = alg.getNumber()[i];
}

PESEL::PESEL(int *num) {
	for (int i = 0; i < 11; i++)  number[i] = num[i];
}

PESEL::PESEL(const string &data) {
	for (int i = 0; i < 11; i++) number[i] = data[i] - '0';
	int tempMonth = number[2] * 10 + number[3];
	int tempYear = number[0] * 10 + number[1];
	year = ((tempMonth/20) < 4)?(1900+(tempMonth/20)*100)+tempYear:1800+tempYear;
	month = tempMonth % 20;
	day = number[4] * 10 + number[5];
}

PESEL::PESEL(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
	Algorithm alg(day, month, year);
	for (int i = 0; i < 11; i++) number[i] = alg.getNumber()[i];
}

int * PESEL::getNumber() {
	return number;
}

string PESEL::toString() {
	string converted;
	for (int i = 0; i < 11; i++) {
		converted += to_string(number[i]);
	}
	return converted;
}

string PESEL::getBirthDate() {
	return to_string(day) + "." + to_string(month) + "." + to_string(year);
}

int PESEL::getDay() const {
	return day;
}

int PESEL::getMonth() const {
	return month;
}

int PESEL::getYear() const {
	return year;
}

ostream& operator<<(ostream &o, const PESEL &p) {
	for (int i = 0; i < 11; i++) o << p.number[i];
	return o;
};

bool operator> (const PESEL &p1, const PESEL &p2)
{
	if (p1.getYear() > p2.getYear()) {
		return true;
	}
	else if (p1.getYear() == p2.getYear()) {
		if (p1.getMonth() > p2.getMonth()) {
			return true;
		}
		else if (p1.getMonth() == p2.getMonth()) {
			if (p1.getDay() > p2.getDay()) {
				return true;
			}
		}
	}
	return false;
}