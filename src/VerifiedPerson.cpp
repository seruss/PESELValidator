#include "pch.h"
#include "VerifiedPerson.h"
#include <iostream>
#include <string>

using namespace std;

VerifiedPerson::VerifiedPerson(const Person &p) {
	name = p.getName();
	surname = p.getSurname();
	address = p.getAddress();
	number = p.getNumber();
	birthDate = p.getNumber().getBirthDate();
	int g = p.getNumber().getNumber()[9];
	if (g % 2 == 0) {
		gender = Kobieta;
	}
	else {
		gender = Mê¿czyzna;
	}
	age = 2020 - p.getNumber().getYear();

}

ostream& operator<<(ostream &o, const VerifiedPerson &p) {
	o << p.name << " " << p.surname << " " << p.number << " " << p.address << " " << p.birthDate << " " << p.getGender() << " " << "Wiek: " << p.age;
	return o;
};

string VerifiedPerson::getBirthDate() {
	return birthDate;
}

string VerifiedPerson::getGender() const {
	if (gender == Kobieta) {
		return "Kobieta";
	}
	else {
		return "Mê¿czyzna";
	}
}

int VerifiedPerson::getAge() {
	return age;
}
