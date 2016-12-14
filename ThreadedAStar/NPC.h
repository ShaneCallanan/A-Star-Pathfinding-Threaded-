#pragma once

#include <vector>
#include "Player.h"


class NPC : public Player
{
private:
	bool m_calculatingPath;
	vector<Tile*> m_path;

	virtual void initializeColour() override;
	virtual void move(unsigned int dt);

public:
	NPC();
	NPC(Tile* tile);
	void update(unsigned int dt) override;
	void setCalculatingPath(bool value);
	void setPath(vector<Tile*> path);
	bool isCalculatingPath() const;
};