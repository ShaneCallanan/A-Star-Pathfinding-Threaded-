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

void TileMap::initializeWalls(pair<int, int> wallCount, Size2D wallSize) 
{
	//min, max 
	const float xPos[2] = { 0, 1 - wallSize.w };
	const float yPos[2] = { 0, 1 - wallSize.h };

	const int xRandMax = xPos[1] * 1000; // To be used with rand() function as
	const int yRandMax = yPos[1] * 1000; // it only works with integer values

	Size2D wallPixelSize = Size2D(wallSize.w * m_size.w, wallSize.h * m_size.h); // in pixels


	for (int i = 0; i < wallCount.first; i++)
	{
		float x, y;

		if (i < wallCount.second) // num walls touching bounds 
		{
			const int minOrMax = rand() % 2;
			y = yPos[minOrMax];
		}
		else
		{
			y = (rand() % yRandMax) / 1000.0f;
		}

		do
		{
			x = (rand() % xRandMax) / 1000.0f;
		} while (intersectsWithWall(x * m_size.w));

		Point2D position = Point2D(x * m_size.w, y * m_size.h);
		Rect wall = Rect(position, wallPixelSize);
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
		Tile* prevTile = nullptr;

		for (int j = 0; j < rows; j++)
		{
			Point2D tilePosition = Point2D(i * tileSize.w, j * tileSize.h);
			TileTypes tileType = getTileType(i, j);
			Tile tile = Tile(tileType, i, j);
			tile.setRectangle(Rect(tilePosition, tileSize));
			tile.initializeColour();

			if (prevTile != nullptr)
			{
				if (prevTile->getType() == TileTypes::WALL)
				{
					if (tileType != TileTypes::WALL)
						m_waypointPoaitions.push_back(tile.getMapPos());
				}
				else
				{
					if (tileType == TileTypes::WALL)	
						m_waypointPoaitions.push_back(prevTile->getMapPos());
				}
			}

			rowOfTiles.push_back(tile);
			prevTile = &rowOfTiles.back();
		}

		m_tiles.push_back(rowOfTiles);
	}
}

void TileMap::initializeWaypoints()
{
	for (int i = 0; i < m_waypointPoaitions.size(); i++)
	{
		Point2D* mapPos = &m_waypointPoaitions[i];
		Tile* waypoint = &m_tiles[mapPos->x][mapPos->y];
		waypoint->setColour(Colour(255, 255, 0, 255));
		m_waypoints.push_back(waypoint);
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



//int TileMap:



Tile* TileMap::getClosestTile(Tile* start, Tile* end)
{
	return new Tile();
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

Size2D TileMap::getSize()
{
	return m_size;
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

bool TileMap::intersectsWithWall(float x)
{
	int wallCount = m_walls.size();

	for (int i = 0; i < wallCount; i++)
	{
		if (m_walls[i].contains(x))
		{
			return true;
		}
	}

	return false;
}