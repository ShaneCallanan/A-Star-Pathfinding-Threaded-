#pragma once

#include "GameSystem.h"
#include "PositionComponent.h"
#include "HealthComponent.h"


class AISystem : public GameSystem
{
public:
	AISystem();
	~AISystem();
	void update(Entity* entity) override;
	void applyPositionLogic(Entity* e, PositionComponent* p);
	void printPosition(EntityType type, PositionComponent* p);
	void moveInRandomDirection(EntityType type, PositionComponent* p);
	bool isDead(HealthComponent* h);
};

