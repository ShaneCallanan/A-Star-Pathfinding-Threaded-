#include "stdafx.h"
#include "AISystem.h"


AISystem::AISystem()
{
}


AISystem::~AISystem()
{
}



void AISystem::update(Entity* entity)
{
	vector<Component*>* components = entity->getComponents();

	for (Component* component : *components)
	{
		PositionComponent* pc = dynamic_cast<PositionComponent*>(component);
		
		if (pc != nullptr)
		{ 
			applyPositionLogic(entity, pc);
		}
	}
}



void AISystem::applyPositionLogic(Entity* e, PositionComponent* p)
{
	EntityType type = e->getType();

	if (type != EntityType::PLAYER && e->isDead() == false)
	{
		moveInRandomDirection(type, p);
		printPosition(type, p);
	}
}



void AISystem::moveInRandomDirection(EntityType type, PositionComponent* p)
{
	bool moveX = rand() & 1;
	bool movePositive = rand() & 1;

	if (moveX)
	{
		p->x += movePositive ? p->moveBy : -p->moveBy;
	}
	else
	{
		p->y += movePositive ? p->moveBy : -p->moveBy;
	}
}



void AISystem::printPosition(EntityType type, PositionComponent* p)
{
	switch (type)
	{
	case EntityType::ALIEN:
		cout << "Alien is at " << p->x << ", " << p->y << endl;
		break;
	case EntityType::DOG:
		cout << "Dog is at " << p->x << ", " << p->y << endl;
		break;
	case EntityType::CAT:
		cout << "Cat is at " << p->x << ", " << p->y << endl;
		break;
	}
}



bool AISystem::isDead(HealthComponent* h)
{
	return h->currentHealth <= h->minHealth;
}