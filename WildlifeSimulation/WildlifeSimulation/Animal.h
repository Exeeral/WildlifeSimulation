#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

#include "Tile.h"

class Animal
{

public:

	friend class Tile;

protected:

	Tile* m_currentTile{};
	bool m_sex{};
	int m_id{};

	inline static int animalID{};

public:

	Animal(bool sex);

	virtual bool isPredator() const = 0;
	void setCurrentTile(Tile* tile);

	friend std::ostream& operator<<(std::ostream& out, Animal& animal);
};

#endif