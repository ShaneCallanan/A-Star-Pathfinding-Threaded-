#pragma once

#include <iostream>
#include "BasicTypes.h"

using namespace std;

#ifdef __APPLE__
#include "SDL2/SDL.h"
#elif defined(_WIN64) || defined(_WIN32)
#include "SDL.h"
#endif



class Renderer
{
private:
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
	const char* m_windowName;
	Size2D m_windowSize;

	bool initializeSDL();
	bool initializeWindow();
	bool initializeRenderer();

public:
	Renderer();
	Renderer(Size2D windowSize, const char* windowName);
	bool initialize();
	void clear(const Colour& colour) const;
	void drawFillRect(const Rect& rectangle, const Colour& colour) const;
	void present() const;
	SDL_Renderer* getRenderer() const;
};