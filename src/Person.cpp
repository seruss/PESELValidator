#include "pch.h"
#include "Person.h"
#include "Male.h"
#include "Female.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person() {
	number = PESEL();
	int gender = number.getNumber()[9];
	if (gender % 2 == 0) {
		Female f;
		name = f.getName();
		surname = f.getSurname();
		address = f.getAddress();
	}
	else {
		Male m;
		name = m.getName();
		surname = m.getSurname();
		address = m.getAddress();
	}
}

Person::Person(const string &name, const string &surname, const string &address, PESEL number) 
{
	this->name = name;
	this->surname = surname;
	this->address = address;
	this->number = number;
};

PESEL Person::getNumber() const {
	return number;
}

string Person::getName() const {
	return name;
}

string Person::getSurname() const {
	return surname;
}

string Person::getAddress() const {
	return address;
}

void Person::setNumber(PESEL &number) {
	this->number = number;
}

void Person::setName(const string &name) {
	this->name = name;
}

void Person::setSurname(const string &surname) {
	this->surname = surname;
}
void Person::setAddress(const string &address) {
	this->address = address;
}

ostream& operator<<(ostream &o, const Person &p) {
	o << p.name << " " << p.surname << " " << p.number << " " << p.address;
	return o;
};	

bool operator> (const Person &p1, const Person &p2) {
	return p1.number > p2.number;
}
