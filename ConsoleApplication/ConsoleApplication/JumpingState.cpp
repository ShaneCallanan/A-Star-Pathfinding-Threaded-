#include "stdafx.h"
#include "JumpingState.h"


JumpingState::JumpingState()
{
	m_stateName = "jumping state";
};

JumpingState::~JumpingState() {}


MyState* JumpingState::handleInstruction(string instruction)
{
	if (instruction == "jump")
	{
		cout << "Already jumping" << endl;
	}
	else if (instruction == "duck")
	{
		cout << "Can't duck in the air" << endl;
	}
	else if (instruction == "land")
	{
		return new StandingState();
	}

	return nullptr;
}