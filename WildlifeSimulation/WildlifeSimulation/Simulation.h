#ifndef HANDLER_H
#define HANDLER_H

#include <vector>

#include "Tile.h"

class Simulation
{
private:

	int m_worldWidth{};
	int m_worldHeight{};
	int m_maxAmountOfTurns{};

	std::vector<Tile*> m_tiles{};


public:
	Simulation(const int worldWidth, const int worldHeight, const int maxTurns) noexcept;

	void populateWorld(int herbivores, const int predators);
	void addAnimal(Animal* animal);

	void printAllAnimalsInfo() const;
	Tile* getTileByCoordinates(const int x, const int y) const;

	void startSimulation();

	void animalStateReset();
	void movementPhase();
	void huntingPhase();
	void breedingPhase();

	void moveAnimalsFromTileToAdjacent(Tile* tile);
};

#endif