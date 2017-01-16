// Lab04_AbstractFactory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include "CharacterFactory.h"

using namespace std;


int main()
{
	vector<Character*> characters;
	Factory* factory = new CharacterFactory();
	characters.push_back(factory->createPlayer());
	characters.push_back(factory->createOpponent());

	for (Character* character : characters)
	{
		character->writeToConsole();
	}

	for (int i = characters.size() - 1; i >= 0; i--)
	{
		characters.erase(characters.begin() + i);
	}

    return 0;
}

