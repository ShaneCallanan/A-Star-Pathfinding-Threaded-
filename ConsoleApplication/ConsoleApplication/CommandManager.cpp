#include "stdafx.h"
#include "CommandManager.h"



CommandManager* CommandManager::m_instance = 0;

CommandManager::CommandManager()
{
}


CommandManager::~CommandManager()
{
}


CommandManager* CommandManager::getInstance()
{
	if (!m_instance)
	{
		m_instance = new CommandManager();
	}

	return m_instance;
}

void CommandManager::pushCommand(Command* command)
{
	m_commandHistory.push_back(command);
}
