#include "stdafx.h"
#include "RenderSystem.h"


RenderSystem::RenderSystem()
{
}


RenderSystem::~RenderSystem()
{
}


void RenderSystem::update(Entity* entity)
{
	vector<Component*>* components = entity->getComponents();

	for (Component* component : *components)
	{
		PositionComponent* pc = dynamic_cast<PositionComponent*>(component);

		if (pc != NULL)
		{
			applyLogic(entity->getType(), pc);
		}
	}
}


void RenderSystem::applyLogic(EntityType type, PositionComponent* p)
{
	switch (type)
	{
	case EntityType::PLAYER:
		cout << "Player being rendered at " << p->x << ", " << p->y << endl;
		break;
	case EntityType::ALIEN:
		cout << "Alien being rendered at " << p->x << ", " << p->y << endl;
		break;
	case EntityType::DOG:
		cout << "Dog being rendered at " << p->x << ", " << p->y << endl;
		break;
	case EntityType::CAT:
		cout << "Cat being rendered at " << p->x << ", " << p->y << endl;
		break;
	}
}