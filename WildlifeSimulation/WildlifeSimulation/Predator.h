#ifndef PREDATOR_H
#define PREDATOR_H

#include "Animal.h"

class Predator : public Animal
{
private:

	inline static int totalAmountOfPredators{};

public:

	Predator(bool sex);

	bool isPredator() const override;
	inline static int getTotalAmountOfPredators()
	{
		return totalAmountOfPredators;
	}
};

#endif