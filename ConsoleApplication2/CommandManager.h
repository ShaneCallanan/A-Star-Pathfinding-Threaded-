#pragma once

#include <vector>
#include "Command.h"

using namespace std;


class CommandManager
{
private:
	static CommandManager* m_instance;
	vector<Command*> m_commandHistory;
	int m_currentCommand;

public:
	CommandManager();
	~CommandManager();
	static CommandManager* getInstance();
	void pushCommand(Command* command);
	void undoLastCommand();
	void redoCommand();
};

