#pragma once

#include "MyState.h"
#include "StandingState.h"



class JumpingState : public MyState
{
public:
	JumpingState();
	~JumpingState();
	MyState* handleInstruction(string instruction);
};