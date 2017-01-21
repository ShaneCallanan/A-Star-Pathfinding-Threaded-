#pragma once

#include "MoveCommand.h"
#include <vector>
using namespace std;


class MacroMoveCommand : public Command
{
private:
	vector<Command*> m_commands;

public:
	MacroMoveCommand(int x, int y);
	~MacroMoveCommand();
	void execute(GameObject* object) override;
	void undo() override;
	void redo() override;
};