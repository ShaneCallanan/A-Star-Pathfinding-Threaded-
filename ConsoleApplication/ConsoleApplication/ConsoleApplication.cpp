// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyState.h"
#include "StandingState.h"


int main()
{
	string action = "nothing";
	MyState* currentState = new StandingState();

	while (action == "nothing")
	{
		string input;
		cin >> input;

		if (input == "exit")
		{
			action = input;
		}
		else
		{
			MyState* newState = currentState->handleInstruction(input);

			if (newState != nullptr) 
			{ 
				currentState->exit();
				delete currentState;
				currentState = newState; 
				currentState->enter();
			}
		}
	}

    return 0;
}

