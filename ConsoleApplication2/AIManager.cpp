#include "stdafx.h"
#include "AIManager.h"


AIManager::AIManager()
	: TIME_PER_MOVE(1),
	  m_timeLeftTillMove(1)
{
}


AIManager::~AIManager()
{
}


bool AIManager::shouldMove(float dt)
{
	bool result = false;
	m_timeLeftTillMove -= dt;

	if (m_timeLeftTillMove <= 0)
	{
		m_timeLeftTillMove = TIME_PER_MOVE;
		result = true;
	}

	return result;
}


Command* AIManager::getCommand()
{
	Command* newCommand;
	bool shouldMakeMoveCommand = rand() & 1;

	if (shouldMakeMoveCommand)
	{
		bool xIsZero = rand() & 1;				// no diagonal movement - x or y move will be zero
		bool positiveValue = rand() & 1;		// avoid two zero values - if positiveValue is true we use 1, else -1

		int xMove = xIsZero ? 0 : (positiveValue ? 1 : -1);
		int yMove = xIsZero ? (positiveValue ? 1 : -1) : 0;

		newCommand = new MoveCommand(xMove, yMove);
	}
	else
	{
		newCommand = new TeleportCommand();
	}

	return newCommand;
}