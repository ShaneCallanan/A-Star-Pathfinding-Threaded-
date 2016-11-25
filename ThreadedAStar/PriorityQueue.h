#pragma once

#include <queue>
using namespace std;


template<typename T, class Container = vector<T>, class Compare = less<typename Container::value_type> >
class PriorityQueue : public priority_queue<T, vector<T>, Compare>
{
public:
	void clear()
	{
		this->c.clear();
	}

	bool searchFor(const T item)
	{
		return find(this->c.begin(), this->c.end(), item) != this->c.end();
	}

	T& at(int index)
	{
		return this->c.at(index);
	}

	void insert(vector<T>* items)
	{
		//this->c.insert(this->c.end(), items->begin(), items->end());

		for (int i = 0; i < items->size(); i++)
		{
			this->push(items->at(i));
		}
	}
};