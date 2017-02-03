#pragma once

#include "GameSystem.h"
#include "PositionComponent.h"


class RenderSystem : public GameSystem
{
public:
	RenderSystem();
	~RenderSystem();
	void update(Entity* entity) override;
	void applyLogic(EntityType type, PositionComponent* p);
};

