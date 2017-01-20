#include "stdafx.h"
#include "InputManager.h"



InputManager* InputManager::m_instance = 0;

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}


InputManager* InputManager::getInstance()
{
	if (!m_instance)
	{
		m_instance = new InputManager();
	}

	return m_instance;
}


vector<Command*> InputManager::processInput(sf::RenderWindow* window)
{
	vector<Command*> newCommands;
	sf::Event evt;

	while (window->pollEvent(evt))
	{
		if (evt.type == sf::Event::KeyReleased)
		{
			switch (evt.key.code)
			{
			case sf::Keyboard::W:
				newCommands.push_back(W);
				break;
			case sf::Keyboard::A:
				newCommands.push_back(A);
				break;
			case sf::Keyboard::S:
				newCommands.push_back(S);
				break;
			case sf::Keyboard::D:
				newCommands.push_back(D);
				break;
			case sf::Keyboard::BackSpace:
				break;
			}
		}
	}
}