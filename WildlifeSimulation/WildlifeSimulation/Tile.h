#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <vector>

#include "Animal.h"

class Tile
{
public:

	friend class Animal;

private:

	int m_xCoordinate{};
	int m_yCoordinate{};
	std::vector<Animal*> m_animalsOnTile{};

public:

	Tile(int x, int y);

	void addAnimalToTile(Animal* animal);
	bool areAnimalsOnTile() const;

	void printAnimalsInfo() const;

	int getAmountOfAnimalsOnTile() const;
	int getXCoordinate() const;
	int getYCoordinate() const;

	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
};

#endif
