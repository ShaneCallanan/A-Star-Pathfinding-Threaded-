#include "NPC.h"


NPC::NPC() {}

NPC::NPC(Tile* tile) :
	Player(tile)
{

}



void NPC::initializeColour()
{
	m_colour = Colour(255, 255, 255);
}