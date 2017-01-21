#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "CommandManager.h"
#include "MoveCommand.h"
#include "TeleportCommand.h"
#include "MacroMoveCommand.h"

using namespace std;



class InputManager
{
public:
	InputManager();
	~InputManager();
	Command* processInput(sf::RenderWindow* window);
};