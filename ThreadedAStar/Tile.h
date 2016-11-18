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
	Point2D m_mapPosition;
	Point2D m_pixelPosition;
	Rect m_rectangle;
	TileTypes m_type;

public:
	Tile();
	Tile(TileTypes type, Point2D mapPosition);
	void initializeColour();
	void update(unsigned int dt);
	void render(Renderer* renderer) const;
	void setRectangle(Rect rectangle);
};