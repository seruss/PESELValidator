#pragma once
#ifndef FEMALE_H
#define FEMALE_H
#include <string>
#include "Human.h"
#include "List.h"

using namespace std;

class Female : public Human
{
private:
	static const string FEMALE_NAMES;
	static List<string> femaleNames;
	void replace(string&, const string&, const string&);
public:
	Female();
};

#endif
