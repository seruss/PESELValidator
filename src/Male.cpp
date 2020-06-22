#include "pch.h"
#include "Male.h"
#include "FileHandler.h"
#include "Random.h"
#include <string>

using namespace std;

const string Male::MALE_NAMES = "maleNames.txt";
List<string> Male::maleNames(FileHandler::init(MALE_NAMES));

Male::Male() {
	name = maleNames.getData(Random(0, 49));
}

ostream& operator<<(ostream &o, const Male &m) {
	o << m.name << " " << m.surname << " " << m.address;
	return o;
};
