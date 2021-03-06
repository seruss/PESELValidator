#include "pch.h"
#include "List.h"
#include "Person.h"
#include "PESEL.h"
#include "VerifiedPerson.h"
#include "Male.h"
#include "Female.h"
#include "FileHandler.h"
#include "Algorithm.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>

using namespace std;

List<VerifiedPerson> newList;
bool extracted = false;

void wrongInput() {
	system("cls");
	cout << "Wprowadzono niepoprawny numer. ";
	cin.clear();
	cin.ignore(100, '\n');
	Sleep(1500);
	system("cls");
}

void save(int DBsize, const string& DBfileName) {
	system("cls");
	FileHandler fh;
	List<Person> list;
	for (int i = 0; i < DBsize; i++) {
		Person p;
		list += p;
	}
	fh.save(DBfileName, list);
	cout << "Pomyślnie zapisano plik. \n";
	Sleep(1500);
}

void checkNumberMenu() {
	system("cls");
	string number;
	cout << "Wprowadz numer pesel do weryfikacji. " << endl;
	cin >> number;
	Algorithm alg(number);
	if (alg.isCorrect()) {
		cout << "Cyfra kontrolna jest poprawna. " << endl;
	}
	else {
		cout << "Cyfra kontrolna jest niepoprawna. " << endl;
	}
	Sleep(2000);
	system("cls");
}

void creatorMenu() {
	system("cls");
	int DBsize = 0;
	string DBfileName;
	char menuChoice = 0;
	while (DBsize < 1) {
		cout << "Podaj pojemność nowej bazy danych \n";
		cin >> DBsize;
		system("cls");
		cin.clear();
		cin.ignore(100, '\n');
	}
	while (DBfileName.empty()) {
		cout << "Podaj nazwę pliku \n";
		cin >> DBfileName;
		system("cls");
		cin.clear();
		cin.ignore(100, '\n');
	}
	while (menuChoice < 49 || menuChoice > 50) {
		cout << "Wybierz format pliku \n\n";
		cout << "1. txt \n";
		cout << "2. csv \n";
		cin >> menuChoice;
		switch (menuChoice) {
		case 49: {
			save(DBsize, DBfileName + ".txt");
			break;
		}
		case 50: {
			save(DBsize, DBfileName + ".csv");
			break;
		}
		default: {
			wrongInput();
			creatorMenu();
		}
		}
		system("cls");
		cin.clear();
		cin.ignore(100, '\n');
	}
}

void listMenu(List<Person> &list) {
	char menuChoice = 0;

	cout << "1. Ekstraktuj dane z numerów PESEL \n";
	cout << "2. Zapisz listę do pliku \n";
	cout << "3. Drukuj listę \n";
	cout << "4. Wyjdź \n";
	cin >> menuChoice;

	switch (menuChoice) {
	case 49: {
		system("cls");
		for(int i=0; i<list.size(); i++) newList += list.getData(i);
		extracted = true;
		cout << "Poprawnie wyekstraktowano dane.";
		Sleep(1500);
		system("cls");
		listMenu(list);
		break;
	}
	case 50: {
		system("cls");
		string DBfileName;
		FileHandler fh;
		while (DBfileName.empty()) {
			cout << "Podaj nazwę pliku \n";
			cin >> DBfileName;
			system("cls");
			cin.clear();
			cin.ignore(100, '\n');
		}
		fh.saveNewDB(DBfileName, newList);
		cout << "Plik zapisano pomyślnie. " << endl;
		Sleep(1500);
		system("cls");
		listMenu(list);
		break;
	}
	case 51: {
		system("cls");
		if (!extracted) {
			list.print();
		}
		else {
			newList.print();
		}
		listMenu(list);
		break;
	}
	case 52: {
		return;
	}
	default: {
		wrongInput();
		listMenu(list);
	}
	}
}

void openMenu() {
	system("cls");
	string fileName;
	FileHandler fh;
	List<Person> list;
	cout << "Wprowadź nazwę pliku razem z rozszerzeniem. " << endl;
	cin >> fileName;
	fh.load(fileName, list);
	system("cls");
	listMenu(list);
}

void mainMenu() {
	char menuChoice = 0;

	cout << "1. Stwórz przykładową bazę danych \n";
	cout << "2. Otwórz istniejącą bazę danych \n";
	cout << "3. Sprawdź pojedynczy numer PESEL \n";
	cout << "4. Wyjdź z programu \n";
	cin >> menuChoice;

	switch (menuChoice) {
	case 49: {
		creatorMenu();
		mainMenu();
		break;
	}
	case 50: {
		openMenu();
		break;
	}
	case 51: {
		checkNumberMenu();
		mainMenu();
		break;
	}
	case 52: {
		return;
	}
	default: {
		wrongInput();
		mainMenu();
		}
	}
}

int main()
{
	cout << "Witaj w programie PESEL multitool!\n" << endl;
	mainMenu();


/*
	List<Person> list;
	
	for (int i = 0; i < 1000; i++) {
		Person p;
		list.pushBack(p);
	}
	FileHandler f;
	f.saveTXT("pliczek", list);
	
	f.loadTXT("pliczek.txt", list);
	list.print();
	
	PESEL p("05241605134");
	cout << p.getBirthDate() << endl;
	*/

	return 0;
}