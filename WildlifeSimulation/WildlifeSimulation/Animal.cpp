#include "Animal.h"
#include "functions.h"

Animal::Animal(bool isMale)
	:m_isMale{ isMale },
	m_id{ animalID },
	m_hasMoved{ false }
{
	++animalID;
}

void Animal::setCurrentTile(Tile* tile)
{
	m_currentTile = tile;
}

void Animal::setHasMoved(bool input)
{
	m_hasMoved = input;
}

bool Animal::isMale() const
{
	return m_isMale;
}

int Animal::getId() const
{
	return m_id;
}

bool Animal::hasMoved() const
{
	return m_hasMoved;
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

	if (animal.isMale())
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