// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <vector>
#include <time.h>
#include "EntityFactory.h"
#include "AISystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"

using namespace std;


int main()
{
	srand(time(NULL));

	vector<GameSystem*> systems;
	systems.push_back(new ControlSystem());
	systems.push_back(new AISystem());
	systems.push_back(new RenderSystem());

	vector<Entity*> entities;
	EntityFactory entityFactory = EntityFactory();
	entities.push_back(entityFactory.createEntity(EntityType::PLAYER));
	entities.push_back(entityFactory.createEntity(EntityType::ALIEN));
	entities.push_back(entityFactory.createEntity(EntityType::DOG));
	entities.push_back(entityFactory.createEntity(EntityType::CAT));


	while (true)
	{
		for (GameSystem* system : systems)
		{
			if (dynamic_cast<AISystem*>(system) != nullptr) { cout << endl << endl << "AI SYSTEM: " << endl << endl; }
			if (dynamic_cast<ControlSystem*>(system) != nullptr) { cout << endl << endl << "CONTROL SYSTEM: " << endl << endl; }
			if (dynamic_cast<RenderSystem*>(system) != nullptr) { cout << endl << endl << "RENDER SYSTEM: " << endl << endl; }

			for (Entity* entity : entities)
			{
				system->update(entity);
			}
		}
	}


    return 0;
}

