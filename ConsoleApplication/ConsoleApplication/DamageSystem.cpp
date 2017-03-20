#include "stdafx.h"
#include "DamageSystem.h"


DamageSystem::DamageSystem()
{
}


DamageSystem::~DamageSystem()
{
}

void DamageSystem::update(Entity * entity)
{
	vector<Component*>* components = entity->getComponents();
	HealthComponent* hc = nullptr;
	PositionComponent* pc = nullptr;

	for (Component* component : *components)
	{
		pc = pc == nullptr ? dynamic_cast<PositionComponent*>(component) : pc;
		hc = hc == nullptr ? dynamic_cast<HealthComponent*>(component) : hc;

		if (pc != nullptr && hc != nullptr)
		{
			applyHealthLogic(entity->getType(), pc, hc);
			break;
		}
	}
}

void DamageSystem::applyHealthLogic(EntityType type, PositionComponent* p, HealthComponent* h)
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

void DamageSystem::printHealthStatus(string type, HealthComponent* h)
{
	cout << type.c_str() << " in fire. Lost 25 health." << endl << "Current health is " << h->currentHealth << endl;

	if (h->currentHealth <= h->minHealth)
	{
		cout << type.c_str() << " is dead." << endl;
	}
}