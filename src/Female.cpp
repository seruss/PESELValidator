#include "pch.h"
#include "Female.h"
#include "FileHandler.h"
#include "Random.h"
#include <string>

using namespace std;

const string Female::FEMALE_NAMES = "femaleNames.txt";
List<string> Female::femaleNames(FileHandler::init(FEMALE_NAMES));

Female::Female() {
	name = femaleNames.getData(Random(0, 49));
	replace(surname, "ski", "ska");
	replace(surname, "cki", "cka");
	replace(surname, "dzki", "dzka");
}

void Female::replace(string& str, const string& from, const string& to) {
	size_t start = str.find(from);
	if (start == std::string::npos)
		return;
	str.replace(start, from.length(), to);
}