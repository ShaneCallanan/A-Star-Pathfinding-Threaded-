#include "Player.h"



Player::Player() {}

Player::Player(Tile* tile) :
	m_currentTile(tile)
{
	m_radius = tile->getRectangle()->size.w / 2;
	m_centre = tile->getRectangle()->getCentre();
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



void Player::setCurrentTile(Tile* tile)
{
	m_currentTile = tile;
}