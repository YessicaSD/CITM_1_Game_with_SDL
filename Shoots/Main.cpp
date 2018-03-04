#include "SDL\include\SDL.h"
#pragma comment (lib,"SDL/x86/SDL2.lib")
#pragma comment (lib,"SDL/x86/SDL2main.lib")

int width = 1920;
int height = 1010;
typedef struct
{
	int x;
	int y;
}position;
int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	
	int escape = 0;

	position red;
	red.x = 960;
	red.y = 540;

	position green;
	green.x = red.x;
	green.y = red.y;

	

	SDL_Window* window; /* Declare a window*/ 
	SDL_Renderer* renderer; // Declare a render

	//Initialize the window and render variable
	window = SDL_CreateWindow("Game", 0,30, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // SDL_RENDERED_ACCELERATED DOES THE RENDERER WITH THE HARDWARE ACCELERATION

	SDL_Rect redRect = { red.x,red.y,50,50 }; // {the x position, the y position, the width,height}
	SDL_Rect greenRect = { green.x,green.y,20,20 }; // {the x position, the y position, the width,height}

	SDL_Event event;
	while (!escape)
	{

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);	// Select the color for drawing. It is set to blue here.								
		SDL_RenderClear(renderer);// Clear the entire screen to our selected color.

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &redRect);
		SDL_RenderPresent(renderer);
		
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_WINDOWEVENT)
			{
				if (event.window.event == SDL_WINDOWEVENT_CLOSE) //https://wiki.libsdl.org/SDL_WindowEvent PREGUNTAR PQ ES EVENT.WINDOW.EVENT Y NO EVENT.WINDOW
					return 1;
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_LEFT && redRect.x >0 && event.type != SDL_KEYUP)
				{
					redRect.x -= 10;
				}
				if (event.key.keysym.sym == SDLK_RIGHT && redRect.x<width - 50 && event.type != SDL_KEYUP)
				{
					redRect.x += 10;
				}
				if (event.key.keysym.sym == SDLK_UP && (redRect.y)>0 && event.type != SDL_KEYUP)
				{
					redRect.y -= 10;
				}
				if (event.key.keysym.sym == SDLK_DOWN && (redRect.y)<height - 50 && event.type != SDL_KEYUP)
				{
					redRect.y += 10;
				}
				if (event.key.keysym.sym == SDLK_ESCAPE && event.type != SDL_KEYUP)
				{
					return 1;
				}

			}
			if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					greenRect.x = redRect.x;
					greenRect.y = redRect.y;
					while (greenRect.x <width)
					{
						SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);	// Select the color for drawing. It is set to blue here.								
						SDL_RenderClear(renderer);// Clear the entire screen to our selected color.

						SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
						SDL_RenderFillRect(renderer, &greenRect);
						greenRect.x += 1;

						SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
						SDL_RenderFillRect(renderer, &redRect);
						

						

						SDL_RenderPresent(renderer);
						
					}
				}
			}
		}

		
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
	return 0;
}

