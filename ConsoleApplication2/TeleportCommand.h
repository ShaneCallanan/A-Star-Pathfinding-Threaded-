#pragma once
#include "Command.h"
class TeleportCommand : public Command
{
private:
	GameObject* m_owner;
	sf::Vector2f m_previousPosition;
	sf::Vector2f m_newPosition;

public:
	TeleportCommand();
	~TeleportCommand();
	void execute(GameObject* object) override;
	void undo() override;
	void redo() override;
};

