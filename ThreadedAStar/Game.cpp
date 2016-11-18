#include "Game.h"


Game::Game() :
	m_player(Player()),
	m_running(true)
{ 
	m_renderer = Renderer(m_settings.windowSize, "Astar");
	m_tileMap = TileMap(m_settings.mapSize, m_settings.windowSize);
}

Game::~Game() { }



void Game::initialize()
{
	m_prevTime = LTimer::gameTime();
	m_running = m_renderer.initialize();
	m_tileMap.initialize();
	initializeNPCs();
}

void Game::initializeNPCs()
{
	for (int i = 0; i < m_settings.numNPCs; i++)
	{
		m_NPCs.push_back(NPC());
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
}

void Game::render(Renderer* renderer) const
{
	renderer->clear(Colour(160, 150, 235));
	m_tileMap.render(renderer);
	renderer->present();
}