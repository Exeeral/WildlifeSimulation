#include "Herbivore.h"

Herbivore::Herbivore(bool sex)
	:Animal{ sex }
{
	++totalAmountOfHerbivores;
}

bool Herbivore::isPredator() const
{
	return false;
}


