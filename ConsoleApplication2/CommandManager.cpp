#include "stdafx.h"
#include "CommandManager.h"



CommandManager* CommandManager::m_instance = 0;

CommandManager::CommandManager()
	: m_currentCommand(-1)
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
	m_currentCommand++;

	// if undos have been applied
	if (m_currentCommand < m_commandHistory.size()) 
	{
		// remove later commands
		m_commandHistory.erase(m_commandHistory.begin() + m_currentCommand, m_commandHistory.end());
	}

	m_commandHistory.push_back(command);
}


void CommandManager::undoLastCommand()
{
	if (m_currentCommand >= 0)
	{
		m_commandHistory[m_currentCommand--]->undo();
	}
}


void CommandManager::redoCommand()
{
	if (m_currentCommand + 1 < m_commandHistory.size())
	{
		m_currentCommand++;
		m_commandHistory[m_currentCommand]->redo();
	}
}