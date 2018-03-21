#include "SDL\include\SDL.h"
#include "SDL\include\SDL_image.h"
#pragma comment(lib, "SDL/SDL2.lib")
#pragma comment(lib, "SDL/SDL2main.lib")
#pragma comment(lib,"SDL/SDL2_image.lib")

#include "Globals.h"
#include "Shoots.h"
#include "Start.h"


int main(int argc, char* argv[])
{
	escape = start();
	

	
	while (escape!=false)
	{
		SDL_RenderCopy(renderer, background, NULL, &backgroundRec);

		//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);	// Select the color for drawing. It is set to blue here.								
		//SDL_RenderClear(renderer);// Clear the entire screen to our selected color.


		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &redRect);

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return 1;
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_LEFT)
				{
					leftPress = true;

				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					rightPress = true;
				}
				if (event.key.keysym.sym == SDLK_UP)
				{
					upPress = true;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					downPress = true;
				}
				if (event.key.keysym.sym == SDLK_ESCAPE)
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
					shoot = true;

				}
				if (event.key.keysym.sym == SDLK_LEFT)
				{
					leftPress = false;

				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					rightPress = false;
				}
				if (event.key.keysym.sym == SDLK_UP)
				{
					upPress = false;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					downPress = false;
				}

			}
		}// fin de bucle


		if (greenRect.x <SCREEN_WIDTH && shoot == true)
		{
			SDL_RenderCopy(renderer, background, NULL, &backgroundRec);

			//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);	// Select the color for drawing. It is set to blue here.								
			//SDL_RenderClear(renderer);// Clear the entire screen to our selected color.

			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderFillRect(renderer, &greenRect);
			greenRect.x += 10;

			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderFillRect(renderer, &redRect);



			SDL_RenderPresent(renderer);
			if (greenRect.x == SCREEN_WIDTH)
				shoot = false;


		}

		if (leftPress == true && redRect.x>0)
		{
			redRect.x -= distanceMovement;
		}
		if (rightPress == true && redRect.x<SCREEN_WIDTH - CHARACTER_WIDTH)
		{
			redRect.x += distanceMovement;
		}
		if (upPress == true && (redRect.y)>0)
		{
			redRect.y -= distanceMovement;
		}
		if (downPress == true && (redRect.y)<SCREEN_HEIGHT - CHARACTER_WIDTH)
		{
			redRect.y += distanceMovement;
		}

	}
	SDL_DestroyTexture(background);
	IMG_Quit();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}