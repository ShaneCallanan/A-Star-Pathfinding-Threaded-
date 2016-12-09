#pragma once

#include "GameSettings.h"
#include "Renderer.h"
#include "LTimer.h"
#include "NPC.h"
#include "PathGenerator.h"
#include "TileMap.h"
#include <vector>


class Game
{
private:
	vector<NPC> m_NPCs;
	PathGenerator m_pathGenerator;
	Player m_player;
	unsigned int m_prevTime;
	Renderer m_renderer;
	bool m_running;
	GameSettings2 m_settings;
	TileMap m_tileMap;

	void initializeNPCs();

public:
	Game();
	~Game();
	void initialize();
	void loop();
	void update(unsigned int dt);
	void updateNPCs(unsigned int dt);
	void render(Renderer* renderer) const;
	void renderNPCs(Renderer* renderer) const;
};