#pragma once

/**Used as an interface for the event dispatcher*/
/*Objects wanting to receive events must inherit from this*/

class EventListener
{
public:
	//list of possible events
	//add your own events here
	enum Event {
		WINDOWEVENT_MOVED,
		PLAYERSELECTEDTHOMAS,
		PLAYERSELECTEDCHRIS,
		PLAYERSELECTEDSARAH,
		NEXTLEVEL,
		START_DATA_RECORDING,
		RIGHT_DOWN,
		LEFT_DOWN,
		RIGHT_UP,
		LEFT_UP,
		JUMP_DOWN,
		JUMP_UP,
		Q_UP,
		Q_DOWN,
		ANY_KEY_DOWN,
		ANY_KEY_UP,
		DEBUG_UP,
		DEBUG_DOWN,
		QUIT
	};

	virtual void onEvent(Event)=0;
};

