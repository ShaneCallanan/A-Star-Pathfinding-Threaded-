#pragma once

#include <vector>
#include "Player.h"


class NPC : public Player
{
private:
	bool m_calculatingPath;
	vector<Tile*> m_path;

	void move(unsigned int dt);

public:
	NPC();
	NPC(Tile* tile);
	void update(unsigned int dt) override;
	void initializeColour() override;
	void setCalculatingPath(bool value);
	void setPath(vector<Tile*> path);
	bool isStopped();
	bool isCalculatingPath() const;
};