#ifndef HANDLER_H
#define HANDLER_H

#include <vector>

#include "Tile.h"

class Handler
{
private:

	int m_worldWidth{};
	int m_worldHeight{};
	std::vector<Tile*> m_tiles{};


public:
	Handler(int worldWidth, int worldHeight);
};
//animal with x, y
//tiles
#endif