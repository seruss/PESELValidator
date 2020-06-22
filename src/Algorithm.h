#pragma once
#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>

using namespace std;

class Algorithm
{
private:
	int number[11];
	static const int weights[];
	void generateNumber(int, int, int);
public:
	Algorithm();
	Algorithm(const string&);
	Algorithm(int, int, int);
	bool isCorrect();
	int * getNumber();
};
#endif

