#include "SDL\include\SDL.h"
#include "SDL\include\SDL_image.h"
#pragma comment(lib, "SDL/SDL2.lib")
#pragma comment(lib, "SDL/SDL2main.lib")
#pragma comment(lib,"SDL/SDL2_image.lib")

#include "Globals.h"
#include "Shoots.h"
#include "Start.h"
#include "Render.h"
#include "CheckInput.h"

int main(int argc, char* argv[])
{
		escape=start();
		
		
	
	while (escape!=false)
	{
		render();
		escape=checkInput();
		

		


		if (g.greenRect.x <SCREEN_WIDTH && shoot == true)
		{
			SDL_RenderCopy(g.renderer, g.background, NULL, &g.backgroundRec);

			//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);	// Select the color for drawing. It is set to blue here.								
			//SDL_RenderClear(renderer);// Clear the entire screen to our selected color.

			SDL_SetRenderDrawColor(g.renderer, 0, 255, 0, 255);
			SDL_RenderFillRect(g.renderer, &g.greenRect);
			g.greenRect.x += 10;

			SDL_SetRenderDrawColor(g.renderer, 255, 0, 0, 255);
			SDL_RenderFillRect(g.renderer, &g.redRect);



			SDL_RenderPresent(g.renderer);
			if (g.greenRect.x == SCREEN_WIDTH)
				shoot = false;


		}

		if (leftPress == true && g.redRect.x>0)
		{
			g.redRect.x -= distanceMovement;
		}
		if (rightPress == true && g.redRect.x<SCREEN_WIDTH - CHARACTER_WIDTH)
		{
			g.redRect.x += distanceMovement;
		}
		if (upPress == true && (g.redRect.y)>0)
		{
			g.redRect.y -= distanceMovement;
		}
		if (downPress == true && (g.redRect.y)<SCREEN_HEIGHT - CHARACTER_WIDTH)
		{
			g.redRect.y += distanceMovement;
		}

	}
	SDL_DestroyTexture(g.background);
	IMG_Quit();
	SDL_DestroyWindow(g.window);
	SDL_DestroyRenderer(g.renderer);
	SDL_Quit();

	return 0;
}