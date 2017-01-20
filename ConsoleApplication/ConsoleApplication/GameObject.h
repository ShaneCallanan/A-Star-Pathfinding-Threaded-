#pragma once

#include "SFML/Graphics.hpp"


class GameObject
{
protected:
	sf::RectangleShape m_shape;
	sf::Color m_selectColor;
	sf::Color m_deselectColor;

public:
	GameObject(int x, int y);
	~GameObject();
	void draw(sf::RenderWindow* window);
	void moveTo(int x, int y);
	void setColors(sf::Color selectColor, sf::Color deselectColor);
};

