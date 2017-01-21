#include "stdafx.h"
#include "MacroMoveCommand.h"


MacroMoveCommand::MacroMoveCommand(int x, int y)
{
	m_commands.push_back(new MoveCommand(x, y));
	m_commands.push_back(new MoveCommand(x, y));
	m_commands.push_back(new MoveCommand(x, y));
}


MacroMoveCommand::~MacroMoveCommand() { }


void MacroMoveCommand::execute(GameObject* object)
{
	for (Command* command : m_commands)
	{
		command->execute(object);
	}
}


void MacroMoveCommand::undo()
{
	for (int i = m_commands.size() - 1; i >= 0; i--)
	{
		m_commands[i]->undo();
	}
}


void MacroMoveCommand::redo()
{
	for (Command* command : m_commands)
	{
		command->redo();
	}
}