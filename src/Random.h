#pragma once
#ifndef RANDOM_H
#define RANDOM_H
#include <random>
#include <time.h>
#include <iostream>

class Random
{
private:
	static std::random_device rd;
	static std::mt19937 rng;
	int number;
public:
	Random(const int &, const int &);
	operator int() {
		return number;
	}
};

#endif