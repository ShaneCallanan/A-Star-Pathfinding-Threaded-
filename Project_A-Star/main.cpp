// Test SDL Tool Chain
#include <SDL.h>

//SDL looks for mainline with this signature (compile errors otherwise)
int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_QUIT;

	return 0;
}