#include "PathGenerator.h"
#include <climits>
#include <algorithm>


PathGenerator::PathGenerator() { }



vector<Tile*> PathGenerator::generatePath(Tile* startNode, Tile* endNode)
{
	resetLists();

	Tile* currentNode;

	startNode->setGCost(0);
	startNode->setHCost(calculateHCost(startNode, endNode));
	startNode->calculateFCost();
	m_openList.push(startNode);

	while (!m_openList.empty())
	{
		currentNode = m_openList.top();
		m_openList.pop();
		m_closedList.push_back(currentNode);

		// If destination node found
		if (currentNode == endNode)
		{
			//////////////////TEMP//////////////////////////////////////////
			int closedListSize = m_closedList.size();                     //
			                                                              //
			for (int i = 0; i < closedListSize; i++)                      //
			{                                                             //
				m_closedList[i]->setColour(Colour(135, 206, 250));        //
			}                                                             //
			////////////////////////////////////////////////////////////////

			while (currentNode->getParentNode() != nullptr)
			{
				m_path.push_back(currentNode);

				//////////////////TEMP///////////////////////
				currentNode->setColour(Colour(0, 0, 255)); //
				/////////////////////////////////////////////

				currentNode = currentNode->getParentNode();
			}

			//////////////////TEMP////////////////////////
			startNode->setColour(Colour(0, 0, 0));      //
			endNode->setColour(Colour(255, 255, 255));  //
			//////////////////////////////////////////////

			return m_path;
		}
		else
		{
			vector<Tile*> adjacentNodes = findAdjacentNodes(currentNode);
			removeNonTraversableNodes(&adjacentNodes);
			removeUsedNodes(&adjacentNodes);
			setParentNodes(currentNode, &adjacentNodes);
			computeCosts(&adjacentNodes, endNode);
			m_openList.insert(&adjacentNodes);
		}
	}

	return m_path;
}




void PathGenerator::removeNonTraversableNodes(vector<Tile*>* nodes)
{
	for (int i = nodes->size() - 1; i >= 0; i--)
	{
		Tile* item = nodes->at(i);

		if (!item->isTraversable())
		{
			nodes->erase(nodes->begin() + i);
		}
	}
}

void PathGenerator::removeUsedNodes(vector<Tile*>* nodes)
{
	for (int i = nodes->size() - 1; i >= 0; i--)
	{
		Tile* item = nodes->at(i);
		bool itemInOpenList = m_openList.searchFor(item);
		bool itemInClosedList = find(m_closedList.begin(), m_closedList.end(), item) != m_closedList.end();

		// If node already in open or closed list
		if (itemInOpenList || itemInClosedList)
		{
			nodes->erase(nodes->begin() + i);
		}
	}
}



void PathGenerator::computeCosts(vector<Tile*>* nodes, Tile* endNode)
{
	for (int i = 0; i < nodes->size(); i++)
	{
		Tile* node = nodes->at(i);

		node->setGCost(); // adds 1 to parent G cost
		node->setHCost(calculateHCost(node, endNode));
		node->calculateFCost();
	}
}

int PathGenerator::calculateHCost(Tile* currentNode, Tile* endNode)
{
	Point2D currentPos = currentNode->getMapPos();
	Point2D endPos = endNode->getMapPos();

	return abs(endPos.x - currentPos.x) + abs(endPos.y - currentPos.y);
}



vector<Tile*> PathGenerator::findAdjacentNodes(Tile* node)
{
	Tile* adjacentNode;
	vector<Tile*> nodes;
	Point2D mapPos = node->getMapPos();

	// Loop surrounding nodes
	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			// If not a diagonal node
			if ((x == 0 && y != 0) || (y == 0 && x != 0))
			{
				adjacentNode = m_tileMap->getTile(mapPos.x + x, mapPos.y + y);

				if (adjacentNode != nullptr)
				{
					nodes.push_back(adjacentNode);
				}
			}
		}
	}

	return nodes;
}



void PathGenerator::resetLists()
{
	m_closedList.clear();
	m_path.clear();
	m_openList.clear();
}



void PathGenerator::setParentNodes(Tile* parentNode, vector<Tile*>* nodes)
{
	for (int i = 0; i < nodes->size(); i++)
	{
		nodes->at(i)->setParentNode(parentNode);
	}
}

void PathGenerator::setTileMap(TileMap* tileMap)
{
	m_tileMap = tileMap;
}