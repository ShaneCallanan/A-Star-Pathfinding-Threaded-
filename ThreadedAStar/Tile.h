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
	Tile* m_parentNode;
	Point2D m_pixelPosition;
	Rect m_rectangle;
	TileTypes m_type;
	bool m_traversable;

public:
	Tile();
	Tile(TileTypes type, int mapPosX, int mapPosY);
	void initializeColour();
	void update(unsigned int dt);
	void render(Renderer* renderer) const;
	void calculateFCost();
	const int getFCost() const;
	const int getGCost() const;
	const int getHCost() const;
	const Point2D getMapPos() const;
	Tile* getParentNode();
	const Rect* getRectangle() const;
	const TileTypes getType() const;
	void reset();
	void setGCost(int value);
	void setHCost(int value);
	void setParentNode(Tile* parentNode);
	void setRectangle(Rect rectangle);
	bool isTraversable();

	void setColour(Colour colour);
};