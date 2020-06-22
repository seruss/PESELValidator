#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
#include "List.h"
#include "Person.h"
#include "VerifiedPerson.h"

using namespace std;

class FileHandler
{
public:
	static List<string> init(const string &);
	static void save(const string &, List<Person> &);
	static void load(const string &, List<Person> &);
	static void saveNewDB(const string &, List<VerifiedPerson> &);

};
#endif
