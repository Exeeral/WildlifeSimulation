#include "Predator.h"

Predator::Predator(bool sex)
	:Animal{ sex }
{
	++totalAmountOfPredators;
}

bool Predator::isPredator() const
{
	return true;
}
