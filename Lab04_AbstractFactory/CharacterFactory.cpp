#include "stdafx.h"
#include "CharacterFactory.h"


CharacterFactory::CharacterFactory()
{

}


CharacterFactory::~CharacterFactory()
{

}


Character* CharacterFactory::createPlayer()
{
	return new Player();
}


Character* CharacterFactory::createOpponent()
{
	return new Boss();
}