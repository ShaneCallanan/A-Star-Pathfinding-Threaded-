#include "stdafx.h"
#include "InputManager.h"



InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}


Command* InputManager::processInput(sf::RenderWindow* window)
{
	Command* newCommand = nullptr;
	sf::Event evt;

	while (window->pollEvent(evt))
	{
		if (evt.type == sf::Event::KeyReleased)
		{
			switch (evt.key.code)
			{
			case sf::Keyboard::W:
				newCommand = new MoveCommand(0, -1);
				break;
			case sf::Keyboard::A:
				newCommand = new MoveCommand(-1, 0);
				break;
			case sf::Keyboard::S:
				newCommand = new MoveCommand(0, 1);
				break;
			case sf::Keyboard::D:
				newCommand = new MoveCommand(1, 0);
				break;
			case sf::Keyboard::J:
				newCommand = new TeleportCommand();
				break;
			case sf::Keyboard::Up:
				newCommand = new MacroMoveCommand(0, -1);
				break;
			case sf::Keyboard::Left:
				newCommand = new MacroMoveCommand(-1, 0);
				break;
			case sf::Keyboard::Down:
				newCommand = new MacroMoveCommand(0, 1);
				break;
			case sf::Keyboard::Right:
				newCommand = new MacroMoveCommand(1, 0);
				break;
			case sf::Keyboard::BackSpace:
				CommandManager::getInstance()->undoLastCommand();
				break;
			case sf::Keyboard::Space:
				CommandManager::getInstance()->redoCommand();
				break;
			}
		}
	}

	return newCommand;
}