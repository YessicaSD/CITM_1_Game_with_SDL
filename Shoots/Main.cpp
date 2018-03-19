#include "SDL\include\SDL.h"
#include "SDL\include\SDL_image.h"
#pragma comment(lib, "SDL/SDL2.lib")
#pragma comment(lib, "SDL/SDL2main.lib")
#pragma comment(lib,"SDL/SDL2_image.lib")


#define distanceMovement 10
int width = 1680;
int height = 1040;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	int escape = 0;

	bool shoot = false;
	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;


	int x0 = 960;
	int y0 = 540;

	SDL_Window* window; /* Declare a window*/
	SDL_Renderer* renderer; // Declare a render
	SDL_Texture*background;
	//Initialize the window and render variable
	window = SDL_CreateWindow("Game", 0, 30, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC); // SDL_RENDERED_ACCELERATED DOES THE RENDERER WITH THE HARDWARE ACCELERATION

	SDL_Surface* image = nullptr;
	image = IMG_Load("../Source/test.png");
	if (image == nullptr)
	{
		return 0;
	}
	else
	{
		background = SDL_CreateTextureFromSurface(renderer, image);
		//SDL_QueryTexture(background, nullptr, nullptr,nullptr, nullptr);
	}
	SDL_Rect backgroundRec = { 0,0,width,height };


	SDL_Rect redRect = { x0,y0,50,50 }; // {the x position, the y position, the width,height}
	SDL_Rect greenRect = { x0,y0,20,20 }; // {the x position, the y position, the width,height}

	SDL_Event event;
	while (!escape)
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
					left = true;

				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					right = true;
				}
				if (event.key.keysym.sym == SDLK_UP)
				{
					up = true;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					down = true;
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
					left = false;

				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					right = false;
				}
				if (event.key.keysym.sym == SDLK_UP)
				{
					up = false;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					down = false;
				}

			}
		}// fin de bucle


		if (greenRect.x <width && shoot == true)
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
			if (greenRect.x == width)
				shoot = false;


		}

		if (left == true && redRect.x>0)
		{
			redRect.x -= distanceMovement;
		}
		if (right == true && redRect.x<width - 50)
		{
			redRect.x += distanceMovement;
		}
		if (up == true && (redRect.y)>0)
		{
			redRect.y -= distanceMovement;
		}
		if (down == true && (redRect.y)<height - 50)
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