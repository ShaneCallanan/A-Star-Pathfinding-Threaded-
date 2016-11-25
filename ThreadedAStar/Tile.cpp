#include "Tile.h"



Tile::Tile() { }

Tile::Tile(TileTypes type, int mapPosX, int mapPosY) :
	m_mapPosX(mapPosX),
	m_mapPosY(mapPosY),
	m_type(type)
{
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


//bool Tile::operator<(const Tile& right) const
//{
//
//}



void Tile::render(Renderer* renderer) const
{
	renderer->drawFillRect(m_rectangle, m_colour);
	//renderer->drawRect(m_rectangle, Colour(85, 0, 0));
}



void Tile::calculateFCost()
{
	m_costF = m_costG + m_costH;
}



const int Tile::getFCost() const
{
	return m_costF;
}

const int Tile::getGCost() const
{
	return m_costG;
}

const Point2D Tile::getMapPos() const
{
	return Point2D(m_mapPosX, m_mapPosY);
}

Tile* Tile::getParentNode()
{
	return m_parentNode;
}

const Rect* Tile::getRectangle() const
{
	return &m_rectangle;
}

const TileTypes Tile::getType() const
{
	return m_type;
}



void Tile::reset()
{
	m_costF = 0;
	m_costG = 0;
	m_costH = 0;
	m_parentNode = nullptr;
}



void Tile::setGCost()
{
	m_costG = m_parentNode->getGCost() + 1;
}

void Tile::setGCost(int value)
{
	m_costG = value;
}

void Tile::setHCost(int value)
{
	m_costH = value;
}

void Tile::setParentNode(Tile* parentNode)
{
	m_parentNode = parentNode;
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