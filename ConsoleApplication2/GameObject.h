#pragma once

#include "SFML/Graphics.hpp"


class GameObject
{
protected:
	sf::RectangleShape m_shape;
	sf::Color m_selectColor;
	sf::Color m_deselectColor;

public:
	GameObject(int x, int y, sf::Color color);
	~GameObject();
	void draw(sf::RenderWindow* window);
	void moveTo(int x, int y);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void setPosition(sf::Vector2f position);
};

