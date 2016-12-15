#pragma once

#include "SDL_thread.h"
#include "Coordinator.h"

class Worker
{
private:
	SDL_Thread* m_thread;

public:
	Worker();

	static int work(void* ptr);
};