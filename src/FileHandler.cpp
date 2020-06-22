#include "pch.h"
#include "FileHandler.h"
#include "Person.h"
#include "VerifiedPerson.h"
#include <fstream>
#include <string>

using namespace std;

List<string> FileHandler::init(const string &fileName) 
{
	List<string> list;
	ifstream file(fileName);
	string s;
	while (getline(file, s)) {
		list.pushFront(s);
	}
	file.close();
	return list;
}

void FileHandler::save(const string &fileName, List<Person> &list) {
	ofstream file;
	file.open(fileName);
	for (int i = 0; i < list.size(); i++) {
		Person p = list.getData(i);
		file << p.getName() << "," << p.getSurname() << "," << p.getNumber() << "," << p.getAddress() << endl;
	}
	file.close();
}

void FileHandler::load(const string &fileName, List<Person> &list) {
	ifstream file;
	file.open(fileName);
	string name, surname, number, address;
	while (getline(file, name, ',')) {
		getline(file, surname, ',');
		getline(file, number, ',');
		getline(file, address);
		list += Person(name, surname, address, PESEL(number));
	}
	file.close();
}


void FileHandler::saveNewDB(const string &fileName, List<VerifiedPerson> &list) {
	ofstream file;
	file.open(fileName);
	for (int i = 0; i < list.size(); i++) {
		VerifiedPerson p = list.getData(i);
		file << p.getName() << "," << p.getSurname() << "," << p.getNumber() << "," << p.getAddress() << "," << p.getBirthDate() << "," << p.getGender() << "," << p.getAge() << endl;
	}
	file.close();
}

