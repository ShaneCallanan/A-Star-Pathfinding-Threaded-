#pragma once

#include "BasicTypes.h"
#include "Tile.h"
#include <vector>
#include <math.h>

using namespace std;


class TileMap
{
private:
	Rect m_npcZone;
	Rect m_playerZone;
	Size2D m_size;
	vector<vector<Tile>> m_tiles;
	vector<Rect> m_walls;

	TileTypes getTileType(int mapX, int mapY);

public:
	TileMap();
	TileMap(Size2D size);
	void initializeZones(Rect playerZone, Rect npcZone);
	void initializeWalls(const Rect walls[]);
	void initializeTiles(Size2D windowSize);
	void update(unsigned int dt);
	void render(Renderer* renderer) const;
	Tile* getRandomTile();
	Tile* getRandomTileOfType(TileTypes type);
	bool isWall(int mapX, int mapY);
};