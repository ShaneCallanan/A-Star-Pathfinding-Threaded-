#include "Renderer.h"

#define SDL_MAIN_HANDLED



Renderer::Renderer() {}

Renderer::Renderer(Size2D windowSize, const char* windowName) :
	m_windowSize(windowSize),
	m_windowName(windowName)
{
}



bool Renderer::initialize()
{
	if (!initializeSDL())
	{
		const char* result = SDL_GetError();
		cout << "Could not initialize SDL: " << SDL_GetError() << endl;
		return false;
	}

	if (!initializeWindow())
	{
		cout << "Could not create window: " << SDL_GetError() << endl;
		return false;
	}

	if (!initializeRenderer())
	{
		cout << "Could not create renderer: " << SDL_GetError() << endl;
		return false;
	}

	return true;
}



bool Renderer::initializeSDL()
{
	int isError = SDL_Init(SDL_INIT_EVERYTHING);
	return isError == 0 ? true : false;
}

bool Renderer::initializeWindow()
{
	m_window = SDL_CreateWindow(m_windowName, 0, 0, m_windowSize.w, m_windowSize.h, SDL_WINDOW_OPENGL);
	return m_window == NULL ? false : true;
}

bool Renderer::initializeRenderer()
{
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	return m_renderer == NULL ? false : true;
}



void Renderer::clear(const Colour& colour) const
{
	SDL_SetRenderDrawColor(m_renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderClear(m_renderer);
}

void Renderer::drawFillRect(const Rect& rectangle, const Colour& colour) const
{
	SDL_SetRenderDrawColor(m_renderer, colour.r, colour.b, colour.g, colour.a);
	SDL_Rect rect = rectangle.getSDLRect();
	SDL_RenderFillRect(m_renderer, &rect);
}

void Renderer::present() const
{
	SDL_RenderPresent(m_renderer);
}



SDL_Renderer* Renderer::getRenderer() const
{
	return m_renderer;
}