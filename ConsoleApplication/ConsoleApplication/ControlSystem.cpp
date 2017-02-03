#include "stdafx.h"
#include "ControlSystem.h"


ControlSystem::ControlSystem()
{
}


ControlSystem::~ControlSystem()
{
}


void ControlSystem::update(Entity* entity)
{
	vector<Component*>* components = entity->getComponents();
	PositionComponent* pc = nullptr;
	ControlComponent* cc = nullptr;

	for (Component* component : *components)
	{
		pc = pc == nullptr ? dynamic_cast<PositionComponent*>(component) : pc;
		cc = pc == nullptr ? dynamic_cast<ControlComponent*>(component) : cc;

		if (pc != nullptr && cc != nullptr)
		{
			cout << "Which direction would you like to go?" << endl;
			string input;
			cin >> input;
			cc->input = input;
			applyPositionLogic(cc, pc);
		}
	}
}


void ControlSystem::applyPositionLogic(ControlComponent* c, PositionComponent* p)
{
	if (c->input == "up")
	{
		p->y += p->moveBy;
	}
	else if (c->input == "left")
	{
		p->x -= p->moveBy;
	}
	else if (c->input == "down")
	{
		p->y -= p->moveBy;
	}
	else if (c->input == "right")
	{
		p->x += p->moveBy;
	}

	cout << "Player at " << p->x << ", " << p->y << endl;
}