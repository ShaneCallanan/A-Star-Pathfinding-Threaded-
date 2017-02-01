#include "stdafx.h"
#include "DuckingState.h"


DuckingState::DuckingState()
{
	m_stateName = "ducking state";
};

DuckingState::~DuckingState() {};


MyState* DuckingState::handleInstruction(string instruction)
{
	if (instruction == "jump")
	{
		return new JumpingState();
	}
	else if (instruction == "duck")
	{
		cout << "Already ducking" << endl;
	}

	return nullptr;
}