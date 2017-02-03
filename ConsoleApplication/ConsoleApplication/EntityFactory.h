#pragma once

#include "Entity.h"
#include "HealthComponent.h"
#include "ControlComponent.h"
#include "PositionComponent.h"
#include "Component.h"


class EntityFactory
{
private:
	void wireUpPlayer(Entity*);
	void wireUpAlien(Entity*);
	void wireUpDog(Entity*);
	void wireUpCat(Entity*);

public:
	EntityFactory();
	~EntityFactory();
	Entity* createEntity(EntityType type);
};

