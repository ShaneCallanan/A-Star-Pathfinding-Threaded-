#pragma once
#include "Character.h"
class Boss :
	public Character
{
public:
	Boss();
	~Boss();
	void writeToConsole() override;
};

