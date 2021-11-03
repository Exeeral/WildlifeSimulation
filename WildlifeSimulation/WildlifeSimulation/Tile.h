#ifndef TILE_H
#define TILE_H

#include <vector>

#include "Animal.h"

class Tile
{
private:

	int m_xCoordinate{};
	int m_yCoordinate{};
	std::vector<Animal*> m_animalsOnTile{};

public:

	Tile(int x, int y);
};

#endif
