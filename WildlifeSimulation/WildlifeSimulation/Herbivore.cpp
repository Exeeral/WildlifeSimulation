#include "Herbivore.h"

Herbivore::Herbivore(bool sex)
	:Animal{ sex }
{
	++totalAmountOfHerbivores;
}

Herbivore::~Herbivore()
{
	--totalAmountOfHerbivores;
}

bool Herbivore::isPredator() const
{
	return false;
}