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

}