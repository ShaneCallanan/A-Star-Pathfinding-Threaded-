#pragma once

#include "GameSystem.h"
#include "PositionComponent.h"
#include "ControlComponent.h"


class ControlSystem : public GameSystem
{
public:
	ControlSystem();
	~ControlSystem();
	void update(Entity* entity) override;
	void applyPositionLogic(ControlComponent * c, PositionComponent * p);
};

