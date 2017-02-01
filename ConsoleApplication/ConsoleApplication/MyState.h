#pragma once

#include <string>
#include <iostream>

using namespace std;


class MyState
{
protected:
	string m_stateName;

public:
	MyState() {};
	virtual ~MyState() {};
	virtual void enter() { cout << "Transitioning to " << m_stateName << endl; };
	virtual void exit() { cout << "Leaving " << m_stateName << endl; };
	virtual MyState* handleInstruction(string instruction) { return nullptr; }; // do nothing unless functionality should be given
};

