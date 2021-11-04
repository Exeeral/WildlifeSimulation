#include <random>
#include <ctime>
#include <iostream>

#include "functions.h"


int functions::generateRandomNumber(int min, int max)
{
	static std::mt19937 seed{ static_cast<unsigned int>(std::time(nullptr)) };
	std::uniform_int_distribution rng{ min, max };

	return rng(seed);
}

void functions::printNullptrError()
{
	std::cout << "ERROR: Nullptr! How dare you?!\n";
}
