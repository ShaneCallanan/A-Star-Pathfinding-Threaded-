#pragma once

#include <deque>
#include <thread>
#include <functional>
#include "SDL_thread.h"
#include "Worker.h"

using namespace std;
typedef function<void()> Job;
class Worker;

class Coordinator
{
private:
	static Coordinator* m_instance;
	deque<Job> m_jobs;
	SDL_mutex* m_jobAccess;
	SDL_sem* m_jobAvailable;
	deque<Worker*> m_workers;
	SDL_mutex* m_mutex;
	int numWorking = 0;
	bool m_useThreads;

public:
	Coordinator();
	void initializeWorkers();
	void addJob(Job job);
	Job getNextJob();
	SDL_sem* getJobAvailable() const;
	void modifyNumWorking(int val);

	static Coordinator* getInstance()
	{
		if (!m_instance)
		{
			m_instance = new Coordinator();
		}

		return m_instance;
	}
};