#pragma once

#include "BasicTypes.h"
#include "Tile.h"
#include <vector>

using namespace std;


class TileMap
{
private:
	Size2D m_size;
	vector<vector<Tile>> m_tiles;
	Size2D m_windowSize;

public:
	TileMap();
	TileMap(Size2D size, Size2D windowSize);
	void initialize();
	void update(unsigned int dt);
	void render(Renderer* renderer) const;
};