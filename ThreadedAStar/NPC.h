#pragma once

#include "Player.h"


class NPC : public Player
{
private:
	Colour m_colour;
	Tile* m_currentTile;

	void initializeColour() override;

public:
	NPC();
	NPC(Tile* tile);
};