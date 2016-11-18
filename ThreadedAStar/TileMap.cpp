#include "TileMap.h"



TileMap::TileMap() { }

TileMap::TileMap(Size2D size, Size2D windowSize) :
	m_size(size),
	m_windowSize(windowSize)
{
}



void TileMap::initialize()
{
	const int columns = m_size.w;
	const int rows = m_size.h;
	const Size2D tileSize = Size2D(m_windowSize.w / columns, m_windowSize.h / rows);

	for (int i = 0; i < columns; i++)
	{
		vector<Tile> rowOfTiles;

		for (int j = 0; j < rows; j++)
		{
			Point2D tileMapPosition = Point2D((float)i, (float)j);
			Point2D tilePosition = Point2D(i * tileSize.w, j * tileSize.h);

			Tile tile = Tile(TileTypes::FLOOR, tileMapPosition);
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