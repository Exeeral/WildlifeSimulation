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
	inline static int totalAmountOfPredators{};
	inline static int totalAmountOfHerbivores{};

public:

	Animal(const bool isMale) noexcept;
	virtual ~Animal() noexcept = default;

	virtual const bool isPredator() const = 0;
	void setCurrentTile(Tile* tile);
	void setHasMoved(const bool input);

	bool isMale() const;
	int getId() const;
	bool hasMoved() const;

	friend std::ostream& operator<<(std::ostream& out, const Animal& animal);
};

#endif