#pragma once

#include "GameObject.h"



class Command
{
public:
	Command() {};
	virtual ~Command() {};
	virtual void execute(GameObject* object) = 0;
	virtual void undo() = 0;
};