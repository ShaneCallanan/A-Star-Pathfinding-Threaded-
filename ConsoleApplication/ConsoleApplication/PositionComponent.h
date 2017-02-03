#pragma once

#include "Component.h"


class PositionComponent : public Component
{
public:
	int x = 10;
	int y = 10;
	int moveBy = 5;

	PositionComponent() {};
	~PositionComponent() override {};
};

