#pragma once
#include "GameSystem.h"
#include "PositionComponent.h"

class DamageSystem : public GameSystem
{
private:
	void applyHealthLogic(EntityType type, PositionComponent* p, HealthComponent* h);
	void printHealthStatus(string type, HealthComponent* h);

public:
	DamageSystem();
	~DamageSystem();
	void update(Entity* entity) override;
};

