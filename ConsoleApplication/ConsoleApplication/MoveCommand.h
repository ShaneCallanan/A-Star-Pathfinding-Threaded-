#pragma once

#include "Command.h"


class MoveCommand : public Command
{
private:
	GameObject* owner;

public:
	MoveCommand(int x, int y);
	void execute() override;
	void undo() override;
};