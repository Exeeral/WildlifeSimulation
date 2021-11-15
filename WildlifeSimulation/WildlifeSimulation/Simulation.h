#ifndef HANDLER_H
#define HANDLER_H

#include <vector>

class Tile;
class Animal;

class Simulation
{
private:

	std::vector<Tile*> m_tiles{};

	int m_worldWidth{};
	int m_worldHeight{};
	int m_maxAmountOfTurns{};

public:
	Simulation(const int worldWidth, const int worldHeight, const int maxTurns) noexcept;

	void populateWorld(int herbivores, const int predators);
	void addAnimal(Animal* animal);

	void printAllAnimalsInfo() const;
	[[nodiscard]] Tile* getTileByCoordinates(const int x, const int y) const;

	void startSimulation();

	void animalStateReset();
	void movementPhase();
	void huntingPhase();
	void breedingPhase();

	void moveAnimalsFromTileToAdjacent(Tile* tile);
};

#endif