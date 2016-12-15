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
	vector<Tile*> m_waypoints;
	vector<Point2D> m_waypointPoaitions;

	TileTypes getTileType(int mapX, int mapY);

public:
	TileMap();
	TileMap(Size2D size);
	void initializeZones(Rect playerZone, Rect npcZone);
	void initializeWalls(pair<int, int> wallCount, Size2D wallSize);
	void initializeTiles(Size2D windowSize);
	void initializeWaypoints();
	void update(unsigned int dt);
	void render(Renderer* renderer) const;
	int calculateDistance(Tile* tile1, Tile* tile2);
	Tile* getClosestTile(Tile* start, Tile* end);
	Tile* getRandomTile();
	Tile* getRandomTileOfType(TileTypes type);
	Size2D getSize();
	Tile* getTile(int x, int y);
	bool isWall(int mapX, int mapY);
	bool intersectsWithWall(float x);
};