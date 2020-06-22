#pragma once
#ifndef MALE_H
#define MALE_H
#include <string>
#include "Human.h"
#include "List.h"

using namespace std;

class Male : public Human
{
private:
	static const string MALE_NAMES;
	static List<string> maleNames;
public:
	Male();
	friend ostream& operator<<(ostream&, const Male&);
};

#endif
