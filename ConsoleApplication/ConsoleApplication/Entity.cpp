#include "stdafx.h"
#include "Entity.h"


Entity::Entity(EntityType type)
	: m_type(type)
{
}


Entity::~Entity()
{
}


void Entity::addComponent(Component* component)
{
	m_components.push_back(component);
}


vector<Component*>* Entity::getComponents()
{
	return &m_components;
}


EntityType Entity::getType()
{
	return m_type;
}


bool Entity::isDead()
{
	for (Component* component : m_components)
	{
		HealthComponent* hc = dynamic_cast<HealthComponent*>(component);
		if (hc != nullptr) { return hc->currentHealth <= hc->minHealth; }
	}

	return false;
}