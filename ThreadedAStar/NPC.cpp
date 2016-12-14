#include "NPC.h"


NPC::NPC() {}

NPC::NPC(Tile* tile) :
	Player(tile),
	m_currentTile(tile),
	m_calculatingPath(false),
	m_aligned(true)
{
}



void NPC::initializeColour()
{
	m_colour = Colour(255, 255, 255);
}



Tile* NPC::getTile()
{
	return m_currentTile;
}



void NPC::setCalculatingPath(bool value)
{
	m_calculatingPath = value;
}

void NPC::setPath(vector<Tile*> path)
{
	m_path = path;
}



bool NPC::isAligned()
{
	return m_aligned;
}

bool NPC::isCalculatingPath() const
{
	return m_calculatingPath;
}