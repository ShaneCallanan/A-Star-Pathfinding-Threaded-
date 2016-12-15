#include "NPC.h"


NPC::NPC() {}

NPC::NPC(Tile* tile) :
	Player(tile),
	m_calculatingPath(false)
{
}



void NPC::initializeColour()
{
	m_colour = Colour(255, 255, 255);
}



void NPC::update(unsigned int dt)
{
	if (m_aligned)
	{
		if (m_path.size() > 0)
		{
			m_aligned = false;
			m_targetTile = m_path.back();
			m_path.pop_back();
			calculateDirection();
		}
	}
	else
	{
		move(dt);
		checkAligned();
	}
}

void NPC::move(unsigned int dt)
{
	Vector2D velocity = m_direction * m_speed;
	m_centre = Point2D(m_centre.x - velocity.x, m_centre.y - velocity.y);
}



void NPC::setCalculatingPath(bool value)
{
	m_calculatingPath = value;
}

void NPC::setPath(vector<Tile*> path)
{
	m_path = path;
}



bool NPC::isCalculatingPath() const
{
	return m_calculatingPath;
}