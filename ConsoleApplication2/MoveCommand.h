#pragma once

#include "Command.h"


class MoveCommand : public Command
{
private:
	GameObject* m_owner;
	sf::Vector2f m_previousPos;
	sf::Vector2f moveBy;

public:
	MoveCommand(int x, int y);
	void execute(GameObject* object) override;
	void undo() override;
	void redo() override;
};