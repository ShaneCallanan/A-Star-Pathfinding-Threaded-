#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "CommandManager.h"

using namespace std;


//class InputManager
//{
//private:
//	static InputManager* m_instance;
//	Command* W;
//	Command* A;
//	Command* S;
//	Command* D;
//
//public:
//	InputManager();
//	~InputManager();
//	static InputManager* getInstance();
//	vector<Command*> processInput(sf::RenderWindow* window);
//};

class InputManager
{
private:
	Command* W;
	Command* A;
	Command* S;
	Command* D;

public:
	InputManager();
	~InputManager();
	vector<Command*> processInput(sf::RenderWindow* window);
};