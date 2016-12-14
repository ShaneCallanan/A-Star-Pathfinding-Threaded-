#pragma once

#include "BasicTypes.h"
#include "Tile.h"


class Player
{
protected:
	bool m_aligned;
	Point2D m_centre;
	Colour m_colour;
	Tile* m_currentTile;
	Vector2D m_direction;
	int m_radius;
	Size2D m_size;
	float m_speed;
	Tile* m_targetTile;

	virtual void initializeColour();

public:
	Player();
	Player(Tile* tile);
	virtual void update(unsigned int dt);
	void render(Renderer* renderer) const;
	void calculateDirection();
	void checkAligned();
	Tile* getTile();
	void setCurrentTile(Tile* tile);
	bool isAligned();
};