#include "PathGenerator.h"
#include <climits>
#include <algorithm>


PathGenerator::PathGenerator() { }



vector<Tile*> PathGenerator::generatePath(Tile* startNode, Tile* endNode)
{
	resetLists();

	startNode->setGCost(0);
	startNode->setHCost(calculateHCost(startNode, endNode));
	startNode->calculateFCost();

	m_openList.push_back(startNode);
	Tile* currentNode;

	while (!m_openList.empty())
	{
		currentNode = m_openList[m_openList.size() - 1];
		m_openList.pop_back();
		Point2D currentPos = currentNode->getMapPos();
		m_listMap[currentPos.x][currentPos.y] = LIST_TYPES::CLOSED;
		drawClosedNode(currentNode);

		// If destination node found
		if (currentNode == endNode)
		{
			while (currentNode->getParentNode() != nullptr)
			{
				m_path.push_back(currentNode);
				drawPathNode(currentNode);
				currentNode = currentNode->getParentNode();
			}

			drawStartEndNode(startNode, endNode);
			return m_path;
		}
		else
		{
			vector<Tile*> adjacentNodes = findAdjacentNodes(currentNode);
			removeUnnecessaryNodes(&adjacentNodes);
			computeCosts(&adjacentNodes, currentNode, endNode);
			addUniqueNodesToOpenList(&adjacentNodes);
		}
	}

	return m_path;
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



void PathGenerator::removeUnnecessaryNodes(vector<Tile*>* nodes)
{
	for (int i = nodes->size() - 1; i >= 0; i--)
	{
		Tile* node = nodes->at(i);
		Point2D nodePos = node->getMapPos();

		if (node->isTraversable() == false || 
			m_listMap[nodePos.x][nodePos.y] == LIST_TYPES::CLOSED)
		{
			nodes->erase(nodes->begin() + i);
		}
	}
}



void PathGenerator::computeCosts(vector<Tile*>* nodes, Tile* current, Tile* end)
{
	int newG = current->getGCost() + 1;

	for (int i = 0; i < nodes->size(); i++)
	{
		Tile* node = nodes->at(i);
		unsigned int nodeGCost = node->getGCost();

		if (newG < nodeGCost)
		{
			node->setGCost(newG);
			node->setHCost(calculateHCost(node, end));
			node->calculateFCost();
			node->setParentNode(current);
		}
	}
}

int PathGenerator::calculateHCost(Tile* currentNode, Tile* endNode)
{
	Point2D currentPos = currentNode->getMapPos();
	Point2D endPos = endNode->getMapPos();

	return abs(endPos.x - currentPos.x) + abs(endPos.y - currentPos.y);
}



void PathGenerator::addUniqueNodesToOpenList(vector<Tile*>* nodes)
{
	int elementsAdded = 0;

	for (int i = 0; i < nodes->size(); i++)
	{
		Tile* node = nodes->at(i);
		Point2D nodePos = node->getMapPos();

		if (m_listMap[nodePos.x][nodePos.y] != LIST_TYPES::OPEN)
		{
			elementsAdded++;
			m_openList.push_back(node);
			m_listMap[nodePos.x][nodePos.y] = LIST_TYPES::OPEN;
		}
	}

	if (elementsAdded > 0)
	{
		sort(m_openList.begin(), m_openList.end(), CompareNodes());
	}
}



void PathGenerator::resetLists()
{
	m_listMap.erase(m_listMap.begin(), m_listMap.end());
	m_path.erase(m_path.begin(), m_path.end());
	m_openList.erase(m_openList.begin(), m_openList.end());
	setupListMap();
}



void PathGenerator::setupListMap()
{
	Size2D tileMapSize = m_tileMap->getSize();

	for (int i = 0; i < tileMapSize.w; i++)
	{
		m_listMap.push_back(vector<int>());

		for (int j = 0; j < tileMapSize.h; j++)
		{
			m_listMap[i].push_back(LIST_TYPES::NONE);
		}
	}
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