#include "Herbivore.h"

Herbivore::Herbivore(const bool isMale) noexcept
	:Animal{ isMale }
{
	++totalAmountOfHerbivores;
}

Herbivore::~Herbivore() noexcept
{
	--totalAmountOfHerbivores;
}

const bool Herbivore::isPredator() const
{
	return false;
}