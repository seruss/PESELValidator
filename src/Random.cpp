#include "pch.h"
#include "Random.h"

using namespace std;

random_device Random::rd;
mt19937 Random::rng(Random::rd());

Random::Random(const int &start, const int &end) {
	uniform_int_distribution<> randomizer(start, end);
	number = randomizer(rng);
}