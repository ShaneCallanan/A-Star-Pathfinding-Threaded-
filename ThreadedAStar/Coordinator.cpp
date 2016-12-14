#include "Coordinator.h"

Coordinator* Coordinator::m_instance = nullptr;
Coordinator::Coordinator() 
{
	int numWorkers = thread::hardware_concurrency() - 1;

	for (int i = 0; i < numWorkers; i++)
	{
		m_workers.push_back(new Worker());
	}

	m_jobAccess = SDL_CreateMutex();
	m_jobAvailable = SDL_CreateSemaphore(0);
}



void Coordinator::addJob(Job job)
{
	SDL_LockMutex(m_jobAccess);
	m_jobs.push_back(job);
	SDL_SemPost(m_jobAvailable);
	SDL_UnlockMutex(m_jobAccess);
}



Job Coordinator::getNextJob()
{
	SDL_LockMutex(m_jobAccess);
	Job job = m_jobs.front();
	m_jobs.pop_front();
	SDL_UnlockMutex(m_jobAccess);

	return job;
}

SDL_sem* Coordinator::getJobAvailable() const
{
	return m_jobAvailable;
}