#pragma once

#include "GameObject.h"
#include <iostream>

using namespace std;


class Command
{
public:
	Command() {};
	virtual ~Command() {};
	virtual void execute(GameObject* object) = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
};