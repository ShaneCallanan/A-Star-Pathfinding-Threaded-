// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "InputManager.h"
#include "Game.h"


int main()
{
	// Seed rand
	srand(time(NULL));

	// Initialize Window
	sf::Vector2f screenSize(1920, 1080);
	sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Command Pattern Demo");

	// Initialize Game Clock
	sf::Clock clock;
	float dt = 0;

	// Initialize Game
	Game game = Game();


	while (window.isOpen())
	{
		clock.restart();
		game.update(dt);
		window.clear();
		game.render(&window);
		window.display();
		dt = clock.getElapsedTime().asSeconds();
	}

    return 0;
}