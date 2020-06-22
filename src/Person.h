#pragma once
#ifndef PERSON_H
#define PERSON_H
#include "PESEL.h"
#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
	PESEL number;
	string name;
	string surname;
	string address;
public:
	Person();
	Person(const string&, const string&, const string&, PESEL);
	PESEL getNumber() const;
	string getName() const;
	string getSurname() const;
	string getAddress() const;
	void setNumber(PESEL&);
	void setName(const string&);
	void setSurname(const string&);
	void setAddress(const string&);
	friend ostream& operator<<(ostream&, const Person&);
	friend bool operator> (const Person &p1, const Person &p2);
};

#endif