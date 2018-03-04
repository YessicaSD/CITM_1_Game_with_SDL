#include "SDL\include\SDL.h"
#pragma comment (lib,"SDL/x86/SDL2.lib")
#pragma comment (lib,"SDL/x86/SDL2main.lib")
#include "Header.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	
	int escape = 0;

	position red;
	red.x = 960;
	red.y = 540;

	SDL_Window* window; /* Declare a window*/ 
	SDL_Renderer* renderer; // Declare a render

	//Initialize the window and render variable
	window = SDL_CreateWindow("Game", 0,30, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // SDL_RENDERED_ACCELERATED DOES THE RENDERER WITH THE HARDWARE ACCELERATION

	
	while (!escape)
	{
		render(renderer,&red);
		escape = events(&red);
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
	return 0;
}