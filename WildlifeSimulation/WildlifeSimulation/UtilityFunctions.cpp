#include <random>
#include <ctime>
#include <iostream>

#include "UtilityFunctions.h"


int UtilityFunctions::generateRandomNumber(int min, int max)
{
	static std::mt19937 seed{ static_cast<unsigned int>(std::time(nullptr)) };
	std::uniform_int_distribution rng{ min, max };

	return rng(seed);
}

void UtilityFunctions::printNullptrError()
{
	std::cout << "ERROR: Nullptr.\n";
}
