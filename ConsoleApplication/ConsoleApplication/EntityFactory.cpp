#include "stdafx.h"
#include "EntityFactory.h"


EntityFactory::EntityFactory()
{
}


EntityFactory::~EntityFactory()
{
}


Entity* EntityFactory::createEntity(EntityType type)
{
	Entity* entity = new Entity(type);

	switch (type)
	{
	case EntityType::PLAYER:
		wireUpPlayer(entity);
		break;
	case EntityType::ALIEN:
		wireUpAlien(entity);
		break;
	case EntityType::DOG:
		wireUpDog(entity);
		break;
	case EntityType::CAT:
		wireUpCat(entity);
		break;
	}

	return entity;
}


void EntityFactory::wireUpPlayer(Entity* player)
{
	player->addComponent(new HealthComponent());
	player->addComponent(new ControlComponent());
	player->addComponent(new PositionComponent());
}


void EntityFactory::wireUpAlien(Entity* alien)
{
	alien->addComponent(new HealthComponent());
	alien->addComponent(new PositionComponent());
}


void EntityFactory::wireUpDog(Entity* dog)
{
	dog->addComponent(new HealthComponent());
	dog->addComponent(new PositionComponent());
}


void EntityFactory::wireUpCat(Entity* cat)
{
	cat->addComponent(new PositionComponent());
}