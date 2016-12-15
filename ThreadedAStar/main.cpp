#include <SDL.h>
#include "Game.h"

int main(int argc, char** argv)
{
	Game game = Game();
	game.initialize();
	game.loop();

	SDL_Quit();

	return 0;
}