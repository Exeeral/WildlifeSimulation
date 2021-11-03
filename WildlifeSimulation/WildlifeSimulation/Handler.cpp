#include <iostream>
#include <algorithm>

#include "Handler.h"
#include "Animal.h"
#include "Herbivore.h"
#include "Predator.h"
#include "functions.h"

Handler::Handler(int worldWidth, int worldHeight, int maxTurns)
	:m_worldWidth{ worldWidth },
	m_worldHeight{ worldHeight },
	m_maxAmountOfTurns{ maxTurns }
{
	m_tiles.reserve(m_worldHeight* m_worldWidth);

	for (int y{}; y <= m_worldHeight; ++y)
	{
		for (int x{}; x <= m_worldWidth; ++x)
		{
			m_tiles.push_back(new Tile{ x, y });
		}
	}
}

void Handler::populateWorld(int herbivores, int predators)
{
	int animalsToAdd{ herbivores + predators };
	for (int counter{}; counter < animalsToAdd; ++counter)
	{
		if (herbivores > 0)
		{
			addAnimal(new Herbivore{ static_cast<bool>(functions::generateRandomNumber(0, 1)) });
			--herbivores;
		}
		else
		{
			addAnimal(new Predator{ static_cast<bool>(functions::generateRandomNumber(0, 1)) });
		}
	}
}

void Handler::addAnimal(Animal* animal)
{
	if (!animal)
	{
		int randomTile{ functions::generateRandomNumber(0, m_tiles.size() - 1) };

		m_tiles[randomTile]->addAnimalToTile(animal);
	}
}

void Handler::printAllAnimalsInfo() const
{
	for (auto& currentTile : m_tiles)
	{
		if (currentTile->areAnimalsOnTile())
		{
			currentTile->printAnimalsInfo();
		}
	}
}

Tile* Handler::getTileByCoordinates(int x, int y) const
{
	auto found{ std::find_if(m_tiles.begin(), m_tiles.end(), [x, y](const Tile& currentTile)
		{
			return (currentTile.getXCoordinate() == x) && (currentTile.getYCoordinate() == y);
		}
	) };

	if (found != m_tiles.end())
	{
		return *found;
	}

	return nullptr;
}

void Handler::startSimulation()
{
	for (int currentTurn{ 1 }; currentTurn <= m_maxAmountOfTurns; ++currentTurn)
	{
		printAllAnimalsInfo();
		std::cin.get();

		std::cout << "TURN: " << currentTurn << '\n';

		if (Herbivore::getTotalAmountOfHerbivores() == 0)
		{
			std::cout << "All herbivores have died out!\n";
			break;
		}
		else if (Predator::getTotalAmountOfPredators() == 0)
		{
			std::cout << "All predators have died out!\n";
			break;
		}

		//animalStateReset();
		//movementPhase();
		//huntingPhase();
		//breedingPhase();
	}
}

void Handler::movementPhase()
{
	for (auto& currentTile : m_tiles)
	{
		if (currentTile->areAnimalsOnTile())
		{
			moveAnimalsFromTileToAdjacent(currentTile);
		}
		
	}
}

void Handler::moveAnimalsFromTileToAdjacent(Tile* tile)
{

	//Tile* targetTile{ getTileByCoordinates() };
}

//void Handler::moveAnimalToRandomAdjacentTile(Animal* animal)
//{
//	if (!animal)
//	{
//		functions::printNullptrError();
//		return;
//	}
//
//	int movementPossibility{ functions::generateRandomNumber(0, 3) };
//	int movementDirectionality{ functions::generateRandomNumber(0, 1) };
//
//	int currentX{ m_tiles[animal->getCurrentTileID()]->getXCoordinate() };
//	int currentY{ m_tiles[animal->getCurrentTileID()]->getYCoordinate() };
//
//	//int isAnimalOnEdge{ isAnimalOnMapEdge(animal) };
//
//	switch (movementPossibility)
//	{
//	case 0:
//		if (movementDirectionality == 0)
//		{
//			currentX += 1;
//		}
//		else
//		{
//			currentX -= 1;
//		}
//
//		break;
//
//	case 1:
//		if (movementDirectionality == 0)
//		{
//			currentY += 1;
//		}
//		else
//		{
//			currentY -= 1;
//		}
//
//		break;
//
//	case 2:
//		if (movementDirectionality == 0)
//		{
//			currentX += 1;
//			currentY += 1;
//		}
//		else
//		{
//			currentX -= 1;
//			currentY -= 1;
//		}
//
//		break;
//
//	case 3:
//		if (movementDirectionality == 0)
//		{
//			currentX -= 1;
//			currentY += 1;
//		}
//		else
//		{
//			currentX += 1;
//			currentY -= 1;
//		}
//
//		break;
//
//	default:
//		std::cout << "Handler::moveAnimalToRandomAdjacentTile ERROR: Unspecified case!\n";
//		return;
//	}
//
//	//if animal is on map's edge and wants to move to non-existing tile,
//	//wrap his location around the map
//	if (currentX >= m_worldWidth)
//	{
//		currentX = 0;
//	}
//	else if (currentX < 0)
//	{
//		currentX = m_worldWidth;
//	}
//
//	if (currentY >= m_worldHeight)
//	{
//		currentY = 0;
//	}
//	else if (currentY < 0)
//	{
//		currentY = m_worldHeight;
//	}
//
//	moveAnimalToCoordinates(animal, currentX, currentY);
//}



