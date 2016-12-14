#pragma once

#include <vector>
#include "Player.h"


class NPC : public Player
{
private:
	bool m_aligned;
	Colour m_colour;
	Tile* m_currentTile;
	vector<Tile*> m_path;
	bool m_calculatingPath;

	void initializeColour() override;

public:
	NPC();
	NPC(Tile* tile);
	Tile* getTile();
	void setCalculatingPath(bool value);
	void setPath(vector<Tile*> path);
	bool isAligned();
	bool isCalculatingPath() const;
};