#include "pch.h"
#include "Algorithm.h"
#include "Random.h"
#include <string>

const int Algorithm::weights[] = { 1,3,7,9,1,3,7,9,1,3 };

void Algorithm::generateNumber(int day, int month, int year) {
	number[0] = (year / 10) % 10;
	number[1] = year % 10;
	int convertedMonth = (year / 100 == 18) ? month + 80 : month + ((year / 100) - 19) * 20;
	number[2] = convertedMonth / 10;
	number[3] = convertedMonth % 10;
	number[4] = day / 10;
	number[5] = day % 10;
	for (int i = 6; i < 10; i++) {
		number[i] = Random(0, 9);
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += (number[i] * weights[i]) % 10;
	}
	number[10] = (10 - (sum % 10)) % 10;
}

Algorithm::Algorithm() {
	int year = Random(1901, 2020);
	int month = Random(1, 12);
	int maxDays;
	if (month == 2) {
		if (year % 100 == 0) {
			maxDays = year % 400 == 0 ? 29 : 28;
		}
		else if (year % 4 == 0) {
			maxDays = 29;
		}
		else {
			maxDays = 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		maxDays = 30;
	}
	else {
		maxDays = 31;
	}
	int day = Random(1, maxDays);
	generateNumber(day, month, year);
}

Algorithm::Algorithm(const string &num) {
	for (int i = 0; i < 11; i++)  number[i] = num[i] - '0';
}

Algorithm::Algorithm(int day, int month, int year) {
	generateNumber(day, month, year);
}

bool Algorithm::isCorrect() {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += (weights[i] * number[i]) % 10;
	}
	int controlDigit = 10 - sum % 10;
	if (controlDigit == number[10]) return true;
	return false;
}

int* Algorithm::getNumber() {
	return number;
}