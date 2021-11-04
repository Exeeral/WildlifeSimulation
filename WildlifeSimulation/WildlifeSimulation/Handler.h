#ifndef HANDLER_H
#define HANDLER_H

#include <vector>

#include "Tile.h"

class Handler
{
private:

	int m_worldWidth{};
	int m_worldHeight{};
	int m_maxAmountOfTurns{};
	std::vector<Tile*> m_tiles{};


public:
	Handler(int worldWidth, int worldHeight, int maxTurns);

	void populateWorld(int herbivores, int predators);
	void addAnimal(Animal* animal);

	void printAllAnimalsInfo() const;
	Tile* getTileByCoordinates(int x, int y) const;

	void startSimulation();

	void animalStateReset();
	void movementPhase();
	void huntingPhase();
	void breedingPhase();

	void moveAnimalsFromTileToAdjacent(Tile* tile);


};

#endif