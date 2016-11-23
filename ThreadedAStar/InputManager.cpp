
#include "InputManager.h"
#include <iostream>
using namespace std;


InputManager * InputManager::m_instance = nullptr;

InputManager::InputManager()
{

}


InputManager::~InputManager()
{

}

InputManager * InputManager::getInstance()
{
	if (m_instance == nullptr)
	{// Creation of InputManager instance 
		m_instance = new InputManager();
	}
	return m_instance;
}

void InputManager::AddListener(EventListener::Event evt, EventListener *listener)
{
	if (listeners.find(evt) == listeners.end())
	{ //event not in map add it.
		listeners[evt] = new std::vector<EventListener*>();
	}

	listeners[evt]->push_back(listener);

}

//Send the events to interested objects
void InputManager::Dispatch(EventListener::Event evt)
{
	if (listeners.find(evt) != listeners.end())
	{
		for (auto const &listener : *listeners[evt]) { //go through all listeners for this event
			listener->onEvent(evt); //Call on event for the listener
		}
	}
}

//Gnereate events
void InputManager::ProcessInput()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.window.event == SDL_WINDOWEVENT_MOVED)
		{
			Dispatch(EventListener::Event::WINDOWEVENT_MOVED);
		}
		switch (e.type) {
			/* Keyboard event */
		case SDL_KEYDOWN:
			Dispatch(EventListener::Event::ANY_KEY_DOWN);
			switch (e.key.keysym.sym)
			{
			case SDLK_1:
				Dispatch(EventListener::Event::PLAYERSELECTEDTHOMAS);
				break;
			case SDLK_2:
				Dispatch(EventListener::Event::PLAYERSELECTEDCHRIS);
				break;
			case SDLK_3:
				Dispatch(EventListener::Event::PLAYERSELECTEDSARAH);
				break;
			case SDLK_HASH:
				Dispatch(EventListener::Event::NEXTLEVEL);
				break;
			case SDLK_F10:
				Dispatch(EventListener::Event::DEBUG_DOWN);
				break;
			case SDLK_d:
				Dispatch(EventListener::Event::RIGHT_DOWN);
				break;
			case SDLK_a:
				Dispatch(EventListener::Event::LEFT_DOWN);
				break;
			case SDLK_SPACE:
				Dispatch(EventListener::Event::JUMP_DOWN);
				break;
			case SDLK_q:
				Dispatch(EventListener::Event::Q_DOWN);
				break;
			}
			break;

		case SDL_KEYUP:
			Dispatch(EventListener::Event::ANY_KEY_UP);
			switch (e.key.keysym.sym)
			{
			case SDLK_l:
				Dispatch(EventListener::Event::START_DATA_RECORDING);
				break;
			case SDLK_d:
				Dispatch(EventListener::Event::RIGHT_UP);
				break;
			case SDLK_a:
				Dispatch(EventListener::Event::LEFT_UP);
				break;
			case SDLK_SPACE:
				Dispatch(EventListener::Event::JUMP_UP);
				break;
			case SDLK_F10:
				Dispatch(EventListener::Event::DEBUG_UP);
				break;
			case SDLK_q:
				Dispatch(EventListener::Event::Q_UP);
				break;
			}
			break;

		case SDL_QUIT:
			Dispatch(EventListener::Event::QUIT);
			break;

		default:
			break;
		}
	}
}
