#pragma once

#include "DuckingState.h"



class StandingState : public MyState
{
public:
	StandingState();
	~StandingState();
	MyState* handleInstruction(string instruction);
};

