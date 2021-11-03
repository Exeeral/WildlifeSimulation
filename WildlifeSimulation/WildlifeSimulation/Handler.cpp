#include "Handler.h"

Handler::Handler(int worldWidth, int worldHeight)
	:m_worldWidth{ worldWidth },
	m_worldHeight{ worldHeight }
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
