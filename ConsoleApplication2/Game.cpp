#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace std;


Game::Game(sf::RenderWindow* window)
	: m_input(InputManager()),
	  m_window(window),
	  m_playerTurn(true)
{
	m_playerUnit = new GameObject(900, 200, sf::Color::Yellow);
	m_enemyUnit = new GameObject(900, 700, sf::Color::Blue);
}


Game::~Game() { }



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
	Command* command = m_input.processInput(m_window);

	if (command != nullptr)
	{
		command->execute(m_playerUnit);
		CommandManager::getInstance()->pushCommand(command);
		changeTurn();
	}
}

void Game::updateAICommands(float dt)
{
	if (m_ai.shouldMove(dt))
	{
		Command* command = m_ai.getCommand();
		command->execute(m_enemyUnit);
		CommandManager::getInstance()->pushCommand(command);
		changeTurn();
	}
}


void Game::render(sf::RenderWindow* window)
{
	m_enemyUnit->draw(window);
	m_playerUnit->draw(window);
}


void Game::changeTurn()
{
	cout << "switching turn" << endl;
	m_playerTurn = !m_playerTurn;
}