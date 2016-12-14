#include "Player.h"



Player::Player() {}

Player::Player(Tile* tile) :
	m_aligned(true),
	m_currentTile(tile),
	m_speed(0.5f)
{
	m_radius = tile->getRectangle()->size.w / 2;
	m_centre = tile->getRectangle()->getCentre();
	//m_position = m_currentTile->getRectangle()->pos;
	m_size = m_currentTile->getRectangle()->size;
	initializeColour();
}



void Player::initializeColour()
{
	m_colour = Colour(0, 0, 0);
}



void Player::update(unsigned int dt)
{

}

void Player::render(Renderer* renderer) const
{
	renderer->drawAtom(m_centre, m_radius, m_colour);
}



void Player::calculateDirection()
{
	m_direction = m_currentTile->getMapPos() - m_targetTile->getMapPos();
}

void Player::checkAligned()
{
	Point2D targetCentre = m_targetTile->getRectangle()->getCentre();
	Point2D distance = m_centre - targetCentre;

	if (abs(distance.x) + abs(distance.y) < m_speed * 2)
	{
		m_centre = targetCentre;
		m_currentTile = m_targetTile;
		m_aligned = true;
	}
}



Tile* Player::getTile()
{
	return m_currentTile;
}



void Player::setCurrentTile(Tile* tile)
{
	m_currentTile = tile;
}



bool Player::isAligned()
{
	return m_aligned;
}