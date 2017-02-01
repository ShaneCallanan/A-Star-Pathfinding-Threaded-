#include "stdafx.h"
#include "StandingState.h"


StandingState::StandingState()
{
	m_stateName = "standing state";
};

StandingState::~StandingState() {};


MyState* StandingState::handleInstruction(string instruction)
{
	if (instruction == "jump")
	{
		return new JumpingState();
	}
	else if (instruction == "duck")
	{
		return new DuckingState();
	}

	return nullptr;
}