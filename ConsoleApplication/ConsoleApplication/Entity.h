#pragma once

#include <vector>
#include "HealthComponent.h"
#include "EntityTypes.h"

using namespace std;


class Entity
{
private:
	EntityType m_type;
	vector<Component*> m_components;

public:
	Entity(EntityType type);
	~Entity();
	void addComponent(Component* component);
	vector<Component*>* getComponents();
	EntityType getType();
	bool isDead();
};

