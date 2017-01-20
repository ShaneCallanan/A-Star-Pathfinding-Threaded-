#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(int x, int y) 
	: m_shape(50, 50)
{
	m_shape.setPosition(x, y);
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


void GameObject::setColors(sf::Color selectColor, sf::Color deselectColor)
{
	m_selectColor = selectColor;
	m_deselectColor = deselectColor;
}