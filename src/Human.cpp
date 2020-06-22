#include "pch.h"
#include "Human.h"
#include "FileHandler.h"
#include "Random.h"
#include "List.h"
#include <string>

using namespace std;

const string Human::SURNAMES = "Surnames.txt";
List<string> Human::surnames(FileHandler::init(SURNAMES));

const string Human::STREETS = "Streets.txt";
List<string> Human::streets(FileHandler::init(STREETS));

const string Human::CITIES = "Cities.txt";
List<string> Human::cities(FileHandler::init(CITIES));

Human::Human() {
	surname = surnames.getData(Random(0, 93));
	street = streets.getData(Random(0, 662)) + " " +to_string(Random(1, 199));
	city = cities.getData(Random(0, 4003));
	address = street + " " + city;
}

string Human::getName() const {
	return name;
}

string Human::getSurname() const {
	return surname;
}

string Human::getAddress() const {
	return address;
}

ostream& operator<<(ostream &o, const Human &h) {
	o << h.name << " " << h.surname << " " << h.address;
	return o;
};