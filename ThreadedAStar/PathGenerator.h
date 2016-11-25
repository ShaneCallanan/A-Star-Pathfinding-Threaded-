#pragma once

#include "TileMap.h"
#include "PriorityQueue.h"
#include "sorted_vector.h"
#include <list>





class PathGenerator
{
private:
	struct CompareTiles
	{
		bool operator() (Tile* lhs, Tile* rhs)
		{
			return rhs->getFCost() < lhs->getFCost();
		}
	};

	vector<Tile*> m_closedList;
	//sorted_vector<Tile*> m_openList;
	//list<Tile*> m_openList;
	PriorityQueue<Tile*, vector<Tile*>, CompareTiles> m_openList;
	vector<Tile*> m_path;
	TileMap* m_tileMap;

	void removeNonTraversableNodes(vector<Tile*>* nodes);
	void removeUsedNodes(vector<Tile*>* nodes);
	int calculateHCost(Tile* currentNode, Tile* endNode);
	void computeCosts(vector<Tile*>* nodes, Tile* endNode);
	vector<Tile*> findAdjacentNodes(Tile* node);
	void resetLists();
	void setParentNodes(Tile* parentNode, vector<Tile*>* nodes);

public:
	PathGenerator();
	vector<Tile*> generatePath(Tile* start, Tile* end);
	void setTileMap(TileMap* tileMap);	
};