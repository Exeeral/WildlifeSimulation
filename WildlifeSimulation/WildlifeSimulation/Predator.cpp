#include "Predator.h"

Predator::Predator(const bool isMale) noexcept
	:Animal{ isMale },
	m_turnsTillStarvation{ maxHungerTillDeath }
{
	++totalAmountOfPredators;
}

Predator::~Predator() noexcept
{
	--totalAmountOfPredators;
}

void Predator::setHasEaten(const bool input)
{
	m_hasEaten = input;
}

void Predator::increaseHunger()
{
	--m_turnsTillStarvation;
}

void Predator::resetHunger()
{
	m_turnsTillStarvation = maxHungerTillDeath;
}

bool Predator::isPredator() const
{
	return true;
}

bool Predator::hasEaten() const
{
	return m_hasEaten;
}

int Predator::getTurnsTillStarvation() const
{
	return m_turnsTillStarvation;
}