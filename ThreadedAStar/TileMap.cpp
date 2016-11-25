#include "TileMap.h"



TileMap::TileMap() { }

TileMap::TileMap(Size2D size) :
	m_size(size)
{
}



void TileMap::initializeZones(Rect playerZone, Rect npcZone)
{
	m_playerZone = Rect(round(playerZone.pos.x * m_size.w), round(playerZone.pos.y * m_size.h),
						round(playerZone.size.w * m_size.w), round(playerZone.size.h * m_size.h));

	m_npcZone = Rect(round(npcZone.pos.x * m_size.w), round(npcZone.pos.y * m_size.h),
					 round(npcZone.size.w * m_size.w), round(npcZone.size.h * m_size.h));
}

void TileMap::initializeWalls(const Rect walls[])
{
	for (int i = 0; i < sizeof(walls); i++)
	{
		Rect wall = Rect(round(walls[i].pos.x * m_size.w), round(walls[i].pos.y * m_size.h),
						 round(walls[i].size.w * m_size.w), round(walls[i].size.h * m_size.h));

		m_walls.push_back(wall);
	}
}

void TileMap::initializeTiles(Size2D windowSize)
{
	const int columns = m_size.w;
	const int rows = m_size.h;
	const Size2D tileSize = Size2D(ceil(windowSize.w / columns), ceil(windowSize.h / rows));

	for (int i = 0; i < columns; i++)
	{
		vector<Tile> rowOfTiles;

		for (int j = 0; j < rows; j++)
		{
			Point2D tilePosition = Point2D(i * tileSize.w, j * tileSize.h);
			TileTypes tileType = getTileType(i, j);
			Tile tile = Tile(tileType, i, j);
			tile.setRectangle(Rect(tilePosition, tileSize));
			tile.initializeColour();

			rowOfTiles.push_back(tile);
		}

		m_tiles.push_back(rowOfTiles);
	}
}



void TileMap::update(unsigned int dt)
{
	const int columns = m_size.w;
	const int rows = m_size.h;

	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			m_tiles[i][j].update(dt);
		}
	}
}



void TileMap::render(Renderer* renderer) const
{
	const int columns = m_size.w;
	const int rows = m_size.h;

	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			m_tiles[i][j].render(renderer);
		}
	}
}



TileTypes TileMap::getTileType(int mapX, int mapY)
{
	if (isWall(mapX, mapY))
	{
		return TileTypes::WALL;
	}
	else if (m_playerZone.contains(mapX, mapY))
	{
		return TileTypes::PLAYERZONE;
	}
	else if (m_npcZone.contains(mapX, mapY))
	{
		return TileTypes::NPCZONE;
	}
	else
	{
		return TileTypes::FLOOR;
	}
}

Tile* TileMap::getRandomTile()
{
	int randomX = rand() % m_tiles.size();
	int randomY = rand() % m_tiles[0].size();

	return &m_tiles[randomX][randomY];
}

Tile* TileMap::getRandomTileOfType(TileTypes type)
{
	Tile* tile;

	do
	{
		tile = getRandomTile();
	} while (tile->getType() != type);
	
	return tile;
}

Tile* TileMap::getTile(int x, int y)
{
	if (x < 0 || x >= m_tiles.size() ||
		y < 0 || y >= m_tiles[0].size())
	{
		return nullptr;
	}
	else
	{
		return &m_tiles[x][y];
	}
}



bool TileMap::isWall(int mapX, int mapY)
{
	for (unsigned int i = 0; i < m_walls.size(); i++)
	{
		if (m_walls[i].contains(mapX, mapY))
		{
			return true;
		}
	}

	return false;
}