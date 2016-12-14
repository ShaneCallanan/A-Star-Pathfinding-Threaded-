#pragma once

#include "TileMap.h"
#include "ListTypes.h"
#include "NPC.h"



class PathGenerator
{
private:
	struct NodeInfo
	{
		int G = numeric_limits<int>::max();
		int H = numeric_limits<int>::max();
		int F = numeric_limits<int>::max();
		int listType = LIST_TYPES::NONE;
		Tile* parent = nullptr;
	};

	TileMap* m_tileMap;

	vector<Tile*> findValidNeighbours(Tile* node, vector<vector<NodeInfo>>* nodeData);
	int calculateHeuristic(Tile* currentNode, Tile* endNode);
	void initializeNodeData(vector<vector<NodeInfo>>* nodeData);
	bool isValidNode(Tile* node, NodeInfo* nodeData);
	bool isDiagonal(int xDiff, int yDiff);
	bool isInMapBounds(int x, int y);

	void drawClosedNode(Tile* closedNode);
	void drawPathNode(Tile* pathNode);
	void drawStartEndNode(Tile* start, Tile* end);

public:
	PathGenerator();
	void generatePath(NPC* npc, Tile* start, Tile* end);
	void setTileMap(TileMap* tileMap);	
};