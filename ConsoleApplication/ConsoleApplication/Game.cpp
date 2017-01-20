#include "stdafx.h"
#include "Game.h"


Game::Game(sf::RenderWindow* window)
	: m_input(InputManager()),
	  m_window(window),
	  MAX_MOVES(2),
	  m_playerTurn(true)
{

}


Game::~Game() { }


void Game::createPlayerUnits(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		GameObject* playerUnit = new GameObject(200 + (i * 200), 200);
		playerUnit->setColors(sf::Color::White, sf::Color::Yellow);
		m_playerUnits.push_back(playerUnit);
	}
}

void Game::createEnemyUnits(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		GameObject* enemyUnit = new GameObject(200 + (i * 400), 500);
		enemyUnit->setColors(sf::Color(115, 162, 239, 255), sf::Color::Blue);
		m_enemyUnits.push_back(enemyUnit);
	}
}



void Game::update(float dt)
{
	if (m_playerTurn)
	{
		updateInputCommands();
	}
	else
	{
		updateAICommands(dt);
	}
}

void Game::updateInputCommands()
{
	vector<Command*> newCommands = m_input.processInput();

	for (Command* command : newCommands)
	{
		command->execute(m_selectedUnit);
		CommandManager::getInstance()->pushCommand(command);
		moveCount++;

		if (moveCount == MAX_MOVES)
		{
			m_playerTurn = !m_playerTurn;
			break;
		}
	}
}

void Game::updateAICommands(float dt)
{
	if (m_ai.shouldMove())
	{
		Command* newCommand = m_ai.update(dt);
		command->execute();
		m_commands.push_back(command);
	}
}


void Game::render(sf::RenderWindow* window)
{
	
}