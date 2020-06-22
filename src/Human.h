#pragma once
#ifndef HUMAN_H
#define HUMAN_H
#include "List.h"
#include <string>

using namespace std;

class Human
{
protected:
	string name;
	string surname;
	string address;
private:
	static const string SURNAMES; 
	static const string STREETS;
	static const string CITIES;
	static List<string> surnames;
	static List<string> streets;
	static List<string> cities;
	string street;
	string city;
public:
	Human();
	string getName() const;
	string getSurname() const;
	string getAddress() const;
	friend ostream& operator<<(ostream&, const Human&);
};

#endif
