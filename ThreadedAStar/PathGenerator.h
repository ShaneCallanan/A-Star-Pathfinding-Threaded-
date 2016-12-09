#pragma once

#include "TileMap.h"
#include "ListTypes.h"



class PathGenerator
{
private:
	struct CompareNodes
	{
		bool operator() (Tile* lhs, Tile* rhs)
		{
			int leftF = lhs->getFCost();
			int rightF = rhs->getFCost();
			
			return leftF > rightF;
		}
	};

	TileMap* m_tileMap;
	vector<vector<int>> m_listMap;													// map of tiles with integer value to determine what list it's in
	vector<Tile*> m_openList;
	vector<Tile*> m_path;

	void removeUnnecessaryNodes(vector<Tile*>* nodes);
	vector<Tile*> findAdjacentNodes(Tile* node);
	void computeCosts(vector<Tile*>* nodes, Tile* current, Tile* end);
	int calculateHCost(Tile* currentNode, Tile* endNode);
	void addUniqueNodesToOpenList(vector<Tile*>* nodes);
	void resetLists();
	void setupListMap();
	void setParentNodes(Tile* parentNode, vector<Tile*>* nodes);

	void drawClosedNode(Tile* closedNode);
	void drawPathNode(Tile* pathNode);
	void drawStartEndNode(Tile* start, Tile* end);

public:
	PathGenerator();
	vector<Tile*> generatePath(Tile* start, Tile* end);
	void setTileMap(TileMap* tileMap);	
};