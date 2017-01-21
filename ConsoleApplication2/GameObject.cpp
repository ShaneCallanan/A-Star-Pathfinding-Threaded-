#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(int x, int y, sf::Color color) 
	: m_shape(sf::Vector2f(50, 50))
{
	m_shape.setPosition(x, y);
	m_shape.setFillColor(color);
}


GameObject::~GameObject()
{
}


void GameObject::draw(sf::RenderWindow* window)
{
	window->draw(m_shape);
}


void GameObject::moveTo(int x, int y)
{
	m_shape.setPosition(x, y);
}


sf::Vector2f GameObject::getPosition()
{
	return m_shape.getPosition();
}


sf::Vector2f GameObject::getSize()
{
	return m_shape.getSize();
}


void GameObject::setPosition(sf::Vector2f position)
{
	m_shape.setPosition(position);
}