#include "Tile.h"

Tile::Tile(int x, int y)
	:m_xCoordinate{ x },
	m_yCoordinate{ y }
{

}

void Tile::addAnimalToTile(Animal* animal)
{
	m_animalsOnTile.push_back(animal);
	animal->setCurrentTile(this);

	std::cout << "New " << *animal << " arrived on " << *this << '\n';
}

bool Tile::areAnimalsOnTile() const
{
	if (m_animalsOnTile.size() > 0)
	{
		return true;
	}

	return false;
}

void Tile::printAnimalsInfo() const
{
	for (auto& currentAnimal : m_animalsOnTile)
	{
		std::cout << *currentAnimal << " on " << *this << '\n';
	}
}

int Tile::getAmountOfAnimalsOnTile() const
{
	return static_cast<int>(m_animalsOnTile.size());
}

int Tile::getXCoordinate() const
{
	return m_xCoordinate;
}

int Tile::getYCoordinate() const
{
	return m_yCoordinate;
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
	out << "Tile(X: " << tile.m_xCoordinate 
		<< ", Y: " << tile.m_yCoordinate << ")";

	return out;
}

