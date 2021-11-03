#include "Animal.h"

Animal::Animal(bool sex)
	:m_sex{ sex },
	m_id{ animalID }
{
	++animalID;
}

void Animal::setCurrentTile(Tile* tile)
{
	m_currentTile = tile;
}

std::ostream& operator<<(std::ostream& out, Animal& animal)
{
	if (animal.isPredator())
	{
		out << "Predator, ";
	}
	else
	{
		out << "Herbivore, ";
	}

	if (animal.m_sex)
	{
		out << "male";
	}
	else
	{
		out << "female";
	}

	out << " (ID: " << animal.m_id << ")";

	return out;
}