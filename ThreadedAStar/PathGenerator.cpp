#include "PathGenerator.h"
#include <climits>
#include <algorithm>


PathGenerator::PathGenerator() { }





void PathGenerator::generatePath(NPC* npc, Tile* startNode, Tile* endNode)
{
	vector<Tile*> openList;
	vector<Tile*> path;

	vector<vector<NodeInfo>> nodeData;													// map of node information
	initializeNodeData(&nodeData);

	Point2D startNodePos = startNode->getMapPos();
	NodeInfo* startNodeInfo = &nodeData.at(startNodePos.x).at(startNodePos.y);
	startNodeInfo->G = 0;
	startNodeInfo->H = calculateHeuristic(startNode, endNode);
	startNodeInfo->F = startNodeInfo->G + startNodeInfo->H;

	openList.push_back(startNode);


	while (!openList.empty())
	{
		Tile* currentNode = openList.back();

		if (openList.size() == 12)
		{
			for (int i = 0; i < openList.size() - 1; i++)
			{
				Point2D pos = openList[i]->getMapPos();
				cout << nodeData.at(pos.x).at(pos.y).F << endl;
			}
			cout << endl << endl;
		}
		
		Point2D currentNodePos = currentNode->getMapPos();
		NodeInfo* currentNodeInfo = &nodeData[currentNodePos.x][currentNodePos.y];
		currentNodeInfo->listType = LIST_TYPES::CLOSED;
		openList.pop_back();

		//drawClosedNode(currentNode);



		if (currentNode == endNode)
		{
			// CREATE PATH
			while (currentNodeInfo->parent != nullptr)
			{
				path.push_back(currentNode);
				//drawPathNode(currentNode);
				currentNode = currentNodeInfo->parent;
				currentNodePos = currentNode->getMapPos();
				currentNodeInfo = &nodeData[currentNodePos.x][currentNodePos.y];
			}

			//drawStartEndNode(startNode, endNode);
			break;
		}
		else
		{
			// CALCULATE A-STAR
			vector<Tile*> neighbours = findValidNeighbours(currentNode, &nodeData);
			int neighbourCount = neighbours.size();
			int newGCost = currentNodeInfo->G + 1;

			// Update info for neighbouring nodes
			for (int i = 0; i < neighbourCount; i++)
			{
				Tile* neighbour = neighbours[i];
				Point2D neighbourPos = neighbour->getMapPos();
				NodeInfo* neighbourInfo = &nodeData[neighbourPos.x][neighbourPos.y];

				// Update info for neighbouring node
				if (newGCost < neighbourInfo->G)
				{
					neighbourInfo->G = newGCost;
					neighbourInfo->H = calculateHeuristic(currentNode, endNode);
					neighbourInfo->F = neighbourInfo->G + neighbourInfo->H;
					neighbourInfo->parent = currentNode;
				}

				// Add neighbouring node to open list
				if (neighbourInfo->listType != LIST_TYPES::OPEN)
				{
					// Sorted insertion
					int insertionIndex = openList.size() - 1;

					for (insertionIndex; insertionIndex >= 0; insertionIndex--)
					{
						Point2D elementPos = openList[insertionIndex]->getMapPos();
						NodeInfo* elementInfo = &nodeData[elementPos.x][elementPos.y];

						if (elementInfo->F >= neighbourInfo->F)
						{
							break;
						}
					}

					if (insertionIndex < 0) { insertionIndex = 0;  }
					openList.insert(openList.begin() + insertionIndex, neighbour);
					neighbourInfo->listType = LIST_TYPES::OPEN;
				}
			}
		}
	}

	npc->setPath(path);
	npc->setCalculatingPath(false);
}



vector<Tile*> PathGenerator::findValidNeighbours(Tile* node, vector<vector<NodeInfo>>* nodeData)
{
	Tile* neighbour;
	NodeInfo* nodeInfo;
	vector<Tile*> validNeighbours;
	Point2D nodePos = node->getMapPos();

	// Loop surrounding nodes
	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			if (!isDiagonal(x, y) && !(x == 0 && y == 0))
			{
				int neighbourX = nodePos.x + x;
				int neighbourY = nodePos.y + y;

				if (isInMapBounds(neighbourX, neighbourY))
				{
					neighbour = m_tileMap->getTile(neighbourX, neighbourY);
					nodeInfo = &nodeData->at(neighbourX).at(neighbourY);

					if (isValidNode(neighbour, nodeInfo))
					{
						validNeighbours.push_back(neighbour);
					}
				}
			}
		}
	}

	return validNeighbours;
}



bool PathGenerator::isInMapBounds(int x, int y)
{
	Size2D mapSize = m_tileMap->getSize();
	return (x >= 0 && x < mapSize.w) && (y >= 0 && y < mapSize.h);
}



int PathGenerator::calculateHeuristic(Tile* currentNode, Tile* endNode)
{
	Point2D currentPos = currentNode->getMapPos();
	Point2D endPos = endNode->getMapPos();

	return abs(endPos.x - currentPos.x) + abs(endPos.y - currentPos.y);
}



void PathGenerator::initializeNodeData(vector<vector<NodeInfo>>* nodeData)
{
	Size2D tileMapSize = m_tileMap->getSize();

	for (int i = 0; i < tileMapSize.w; i++)
	{
		nodeData->push_back(vector<NodeInfo>());

		for (int j = 0; j < tileMapSize.h; j++)
		{
			nodeData->at(i).push_back(NodeInfo());
		}
	}
}



void PathGenerator::setTileMap(TileMap* tileMap)
{
	m_tileMap = tileMap;
}



bool PathGenerator::isDiagonal(int xDiff, int yDiff)
{
	return xDiff != 0 && yDiff != 0;
}

bool PathGenerator::isValidNode(Tile* node, NodeInfo* nodeInfo)
{
	return node->isTraversable() && nodeInfo->listType != LIST_TYPES::CLOSED;
}




// TEMP FUNCTIONS

void PathGenerator::drawClosedNode(Tile* closedNode)
{
	closedNode->setColour(Colour(135, 206, 250)); // LIGHT BLUE
}

void PathGenerator::drawPathNode(Tile* pathNode)
{
	pathNode->setColour(Colour(0, 0, 255)); // BLUE
}

void PathGenerator::drawStartEndNode(Tile* start, Tile* end)
{
	start->setColour(Colour(0, 0, 0)); // BLACK
	end->setColour(Colour(255, 255, 255)); // WHITE
}