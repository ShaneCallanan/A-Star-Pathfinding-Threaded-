#include "Coordinator.h"
#include <iostream>

Coordinator* Coordinator::m_instance = 0;
Coordinator::Coordinator() 
	: m_useThreads(true)
{
	m_jobAccess = SDL_CreateMutex();
	m_jobAvailable = SDL_CreateSemaphore(0);
	m_mutex = SDL_CreateMutex();
}



void Coordinator::initializeWorkers()
{
	int numWorkers = m_useThreads ? thread::hardware_concurrency() - 1 : 1;

	for (int i = 0; i < numWorkers; i++)
	{
		m_workers.push_back(new Worker());
	}
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


void Coordinator::modifyNumWorking(int val)
{
	SDL_LockMutex(m_mutex);
	numWorking += val;
	SDL_UnlockMutex(m_mutex);
}