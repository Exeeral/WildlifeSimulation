#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "Animal.h"

class Herbivore : public Animal
{
private:

	inline static int totalAmountOfHerbivores{};

public:

	Herbivore(bool sex);

	bool isPredator() const override;
	inline static int getTotalAmountOfHerbivores()
	{
		return totalAmountOfHerbivores;
	}
};

#endif