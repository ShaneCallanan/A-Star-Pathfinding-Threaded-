#include "Game.h"
#include <time.h>
#include <algorithm>


Game::Game() :
	m_pathGenerator(PathGenerator()),
	m_running(true)
{ 
	srand(time(NULL));
	m_renderer = Renderer(m_settings.windowSize, "Astar");
	m_tileMap = TileMap(m_settings.mapSize);
	m_coordinator = Coordinator::getInstance();
}

Game::~Game() { }



void Game::initialize()
{
	m_running = m_renderer.initialize();

	if (m_running)
	{
		m_tileMap.initializeZones(m_settings.playerZoneAsPercentage, m_settings.npcZoneAsPercentage);
		m_tileMap.initializeWalls(m_settings.wallsAsPercentage);
		m_tileMap.initializeTiles(m_settings.windowSize);
		m_pathGenerator.setTileMap(&m_tileMap);
		m_player = Player(m_tileMap.getRandomTileOfType(TileTypes::PLAYERZONE));
		initializeNPCs();

		Tile* startTile = m_tileMap.getRandomTileOfType(TileTypes::FLOOR);
		Tile* endTile = m_tileMap.getRandomTileOfType(TileTypes::FLOOR);
		m_coordinator->addJob(bind(&PathGenerator::generatePath, &m_pathGenerator, &m_NPCs[0], startTile, endTile));
	}
}

void Game::initializeNPCs()
{
	vector<Tile*> startingTiles;

	for (int i = 0; i < m_settings.numNPCs; i++)
	{
		Tile* tile;

		do
		{
			tile = m_tileMap.getRandomTileOfType(TileTypes::NPCZONE);
		} while (find(startingTiles.begin(), startingTiles.end(), tile) != startingTiles.end());

		startingTiles.push_back(tile);
		m_NPCs.push_back(NPC(tile));
	}
}



void Game::loop()
{
	while (m_running)
	{
		unsigned int currentTime = LTimer::gameTime();
		unsigned int deltaTime = currentTime - m_prevTime;
		m_prevTime = currentTime;

		update(deltaTime);
		render(&m_renderer);
	}
}

void Game::update(unsigned int dt)
{
	m_tileMap.update(dt);
	updateNPCs(dt);
}

void Game::updateNPCs(unsigned int dt)
{
	const int npcCount = m_NPCs.size();

	for (int i = 0; i < npcCount; i++)
	{
		NPC* npc = &m_NPCs[i];
		/*bool calculatingPath = npc->isCalculatingPath();
		bool aligned = npc->isAligned();

		if (!npc->isCalculatingPath() && npc->isAligned())
		{
			Tile* startTile = npc->getTile();
			Tile* endTile = m_player.getTile();
			m_coordinator->addJob(bind(&PathGenerator::generatePath, &m_pathGenerator, npc, startTile, endTile));
			npc->setCalculatingPath(true);
		}*/
		
		npc->update(dt);
	}
}



void Game::render(Renderer* renderer) const
{
	renderer->clear(Colour(160, 150, 235));
	m_tileMap.render(renderer);
	renderNPCs(renderer);
	renderer->present();
}

void Game::renderNPCs(Renderer* renderer) const
{
	const int npcCount = m_NPCs.size();

	for (int i = 0; i < npcCount; i++)
	{
		m_NPCs[i].render(renderer);
	}
}