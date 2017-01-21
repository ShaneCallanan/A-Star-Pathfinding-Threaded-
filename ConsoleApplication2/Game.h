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

	GameObject* m_playerUnit;
	GameObject* m_enemyUnit;

	bool m_playerTurn;

public:
	Game(sf::RenderWindow* window);
	~Game();
	void update(float dt);
	void updateInputCommands();
	void updateAICommands(float dt);
	void render(sf::RenderWindow* window);
	void changeTurn();
};

