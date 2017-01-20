#pragma once

#include "SFML\Graphics.hpp"
#include "InputManager.h"
#include "AIManager.h"


class Game
{
private:
	sf::RenderWindow* m_window;

	AIManager m_ai;
	InputManager m_input;

	vector<GameObject*> m_playerUnits;
	vector<GameObject*> m_enemyUnits;
	GameObject* m_selectedUnit;

	const int MAX_MOVES;
	int moveCount;
	bool m_playerTurn;

public:
	Game(sf::RenderWindow* window);
	~Game();
	void createPlayerUnits(int amount);
	void createEnemyUnits(int amount);
	void update(float dt);
	void updateInputCommands();
	void updateAICommands(float dt);
	void render(sf::RenderWindow* window);
};

