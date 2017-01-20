#pragma once

#include "Command.h"


class AIManager
{
private:
	const int TIME_PER_MOVE;
	float m_timeLeftTillMove;

public:
	AIManager();
	~AIManager();
	bool shouldMove(float dt);
	Command* getCommand();
};

