#include "Worker.h"


Worker::Worker()
{
	m_thread = SDL_CreateThread(&work, "Worker", (void*)NULL);
}

int Worker::work(void* ptr)
{
	Coordinator* coordinator = Coordinator::getInstance();
	SDL_sem* jobAvailable = coordinator->getJobAvailable();

	while (true)
	{
		SDL_SemWait(jobAvailable);
		Job job = coordinator->getNextJob();
		job();
	}
}