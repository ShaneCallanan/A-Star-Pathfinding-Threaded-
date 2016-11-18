#include "Tile.h"



Tile::Tile() { }

Tile::Tile(TileTypes type, Point2D mapPosition) :
	m_mapPosition(mapPosition),
	m_type(type)
{
}



void Tile::initializeColour()
{
	switch (static_cast<TileTypes>(m_type))
	{
	case TileTypes::FLOOR:
		m_colour = Colour(0, 0, 255);
		break;
	case TileTypes::WALL:
		m_colour = Colour(255, 255, 255);
		break;
	}
}



void Tile::update(unsigned int dt)
{

}



void Tile::render(Renderer* renderer) const
{
	renderer->drawFillRect(m_rectangle, m_colour);
}



void Tile::setRectangle(Rect rectangle)
{
	m_rectangle = rectangle;
}