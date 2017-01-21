#include "stdafx.h"
#include "TeleportCommand.h"


TeleportCommand::TeleportCommand()
{
}


TeleportCommand::~TeleportCommand()
{
}


void TeleportCommand::execute(GameObject* object)
{
	m_owner = object;
	m_previousPosition = object->getPosition();
	sf::Vector2f objectSize = object->getSize();

	m_newPosition = sf::Vector2f(rand() % (1920 - (int)objectSize.x), rand() % (1080 - (int)objectSize.y));
	object->setPosition(m_newPosition);
}


void TeleportCommand::undo()
{
	m_owner->setPosition(m_previousPosition);
}


void TeleportCommand::redo()
{
	m_owner->setPosition(m_newPosition);
}