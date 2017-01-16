#pragma once

#include "Character.h"


class Factory
{
public:
	Factory();
	~Factory();
	virtual Character* createPlayer() = 0;
	virtual Character* createOpponent() = 0;
};

