#pragma once

#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;


class GameSystem
{
public:
	GameSystem();
	~GameSystem();
	virtual void update(Entity* entity) {};
};

