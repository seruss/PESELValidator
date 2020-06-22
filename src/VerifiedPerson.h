#pragma once
#ifndef VERIFIEDPERSON_H
#define VERIFIEDPERSON_H
#include "Person.h"

//TODO: ekstrakcja dodatkowych danych w konstruktorze

class VerifiedPerson : public Person
{
	enum Gender {
		Kobieta, Mê¿czyzna
	};
private:
	string birthDate;
	Gender gender;
	int age;
	bool isCorrect;
public:
	VerifiedPerson(const Person&);
	VerifiedPerson() {};
	friend ostream& operator<<(ostream&, const VerifiedPerson&);
	string getBirthDate();
	string getGender() const;
	int getAge();
};

#endif
