#include "Tile.h"
#include <limits>



Tile::Tile() { }

Tile::Tile(TileTypes type, int mapPosX, int mapPosY) :
	m_mapPosX(mapPosX),
	m_mapPosY(mapPosY),
	m_type(type)
{
	m_mapPosAccess = SDL_CreateMutex();
	m_traversable = type == TileTypes::WALL ? false : true;
}



void Tile::initializeColour()
{
	switch (m_type)
	{
	case TileTypes::FLOOR:
		m_colour = Colour(170, 57, 57);
		break;
	case TileTypes::WALL:
		m_colour = Colour(128, 21, 21);
		break;
	case TileTypes::PLAYERZONE:
		m_colour = Colour(212, 106, 106);
		break;
	case TileTypes::NPCZONE:
		m_colour = Colour(255, 170, 170);
		break;
	}
}



void Tile::update(unsigned int dt)
{

}



void Tile::render(Renderer* renderer) const
{
	renderer->drawFillRect(m_rectangle, m_colour);
	//renderer->drawRect(m_rectangle, Colour(85, 0, 0));
}



const Point2D Tile::getMapPos() const
{
	return Point2D(m_mapPosX, m_mapPosY);
}

const Rect* Tile::getRectangle() const
{
	return &m_rectangle;
}

const TileTypes Tile::getType() const
{
	return m_type;
}



void Tile::setRectangle(Rect rectangle)
{
	m_rectangle = rectangle;
}



bool Tile::isTraversable()
{
	return m_traversable;
}




//TEMP
void Tile::setColour(Colour colour)
{
	m_colour = colour;
}