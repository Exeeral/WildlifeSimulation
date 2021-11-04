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
	bool m_isMale{};
	int m_id{};
	bool m_hasMoved{};

	inline static int animalID{};

public:

	Animal(bool isMale);
	virtual ~Animal() = default;

	virtual bool isPredator() const = 0;
	void setCurrentTile(Tile* tile);
	void setHasMoved(bool input);

	bool isMale() const;
	int getId() const;
	bool hasMoved() const;

	friend std::ostream& operator<<(std::ostream& out, Animal& animal);
};

#endif