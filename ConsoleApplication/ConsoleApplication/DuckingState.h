#pragma once

#include "JumpingState.h"



class DuckingState : public MyState
{
public:
	DuckingState();
	~DuckingState();
	MyState* handleInstruction(string instruction) override;
};