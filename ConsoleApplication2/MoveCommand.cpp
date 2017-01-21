#include "stdafx.h"
#include "MoveCommand.h"


MoveCommand::MoveCommand(int x, int y)
	: moveBy(x, y)
{
}


void MoveCommand::execute(GameObject* object)
{
	m_owner = object;
	m_previousPos = object->getPosition();
	sf::Vector2f objectSize = object->getSize();
	sf::Vector2f moveAmount = sf::Vector2f(moveBy.x * objectSize.x, moveBy.y * objectSize.y);
	object->setPosition(m_previousPos + moveAmount);
}


void MoveCommand::undo()
{
	cout << "undoing move command" << endl;
	cout << "currently: " << m_owner->getPosition().x << ", " << m_owner->getPosition().y << endl;
	m_owner->setPosition(m_previousPos);
	cout << "now: " << m_owner->getPosition().x << ", " << m_owner->getPosition().y << endl;
}


void MoveCommand::redo()
{
	execute(m_owner);
}