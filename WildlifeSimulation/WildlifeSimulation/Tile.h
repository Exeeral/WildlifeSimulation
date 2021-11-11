#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <vector>

class Animal;

class Tile
{
public:

	friend class Animal;

private:

	int m_xCoordinate{};
	int m_yCoordinate{};

	int m_malePredators{};
	int m_femalePredators{};

	int m_maleHerbivores{};
	int m_femaleHerbivores{};
	
	std::vector<Animal*> m_animalsOnTile{};

public:

	Tile(int x, int y) noexcept;

	void addAnimalToTile(Animal* animal);
	bool areAnimalsOnTile() const;
	void removeAnimal(Animal* animal);
	void resetAnimalsState();

	void findPredatorAndEatHerbivore();

	void printAnimalsInfo() const;

	int getAmountOfAnimalsOnTile() const;
	int getAmountOfPredatorsOnTile() const;
	int getAmountOfHerbivoresOnTile() const;
	int getXCoordinate() const;
	int getYCoordinate() const;
	Animal* getAnimalOnIndex(const int index) const;

	int getAmountOfHerbivoreBreeds() const;
	int getAmountOfPredatorBreeds() const;

	friend std::ostream& operator<<(std::ostream& out, const Tile& tile);
};

#endif
