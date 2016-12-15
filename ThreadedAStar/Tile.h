#pragma once

#include "BasicTypes.h"
#include "TileTypes.h"
#include "Renderer.h"


class Tile
{
private:
	Colour m_colour;
	int m_mapPosX;
	int m_mapPosY;
	Point2D m_pixelPosition;
	Rect m_rectangle;
	TileTypes m_type;
	bool m_traversable;
	SDL_mutex* m_mapPosAccess;
	//SDL_sem* m_mapPosWriters;

public:
	Tile();
	Tile(TileTypes type, int mapPosX, int mapPosY);
	void initializeColour();
	void update(unsigned int dt);
	void render(Renderer* renderer) const;
	Point2D getMapPos();
	const Rect* getRectangle() const;
	const TileTypes getType() const;
	void setRectangle(Rect rectangle);
	bool isTraversable();

	void setColour(Colour colour);
};