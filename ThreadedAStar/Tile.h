#pragma once

#include "BasicTypes.h"
#include "TileTypes.h"
#include "Renderer.h"


class Tile
{
private:
	Colour m_colour;
	float m_costF;
	float m_costG;
	float m_costH;
	int m_mapPosX;
	int m_mapPosY;
	Point2D m_pixelPosition;
	Rect m_rectangle;
	TileTypes m_type;

public:
	Tile();
	Tile(TileTypes type, int mapPosX, int mapPosY);
	void initializeColour();
	void update(unsigned int dt);
	void render(Renderer* renderer) const;
	const Rect* getRectangle() const;
	TileTypes getType() const;
	void setRectangle(Rect rectangle);
};