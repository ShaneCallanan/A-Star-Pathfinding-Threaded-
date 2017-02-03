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
	PositionComponent* pc = nullptr;
	HealthComponent* hc = nullptr;

	for (Component* component : *components)
	{
		pc = pc == nullptr ? dynamic_cast<PositionComponent*>(component) : pc;
		hc = hc == nullptr ? dynamic_cast<HealthComponent*>(component) : hc;
		
		if (dynamic_cast<PositionComponent*>(component) != nullptr)
		{ 
			applyPositionLogic(entity, pc);
		}
		
		if (pc != nullptr && hc != nullptr)
		{
			applyHealthLogic(entity->getType(), pc, hc);
			break;
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



void AISystem::applyHealthLogic(EntityType type, PositionComponent* p, HealthComponent* h)
{
	if (p->x < 0 || p->x > 20 || p->y < 0 || p->y > 20)
	{
		h->currentHealth -= 25;

		switch (type)
		{
		case EntityType::PLAYER:
			printHealthStatus("Player", h);
			break;
		case EntityType::ALIEN:
			printHealthStatus("Alien", h);
			break;
		case EntityType::DOG:
			printHealthStatus("Dog", h);
			break;
		case EntityType::CAT:
			printHealthStatus("Cat", h);
			break;
		}
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

void AISystem::printHealthStatus(string type, HealthComponent* h)
{
	cout << type.c_str() << " in fire. Lost 25 health." << endl << "Current health is " << h->currentHealth << endl;

	if (h->currentHealth <= h->minHealth)
	{
		cout << type.c_str() << " is dead." << endl;
	}
}



bool AISystem::isDead(HealthComponent* h)
{
	return h->currentHealth <= h->minHealth;
}