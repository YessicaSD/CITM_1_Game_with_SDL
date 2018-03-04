#ifndef _HEADER_H_
#define _HEADER_H_
int width = 1920;
int height = 1020;
typedef struct
{
	int x;
	int y;
}position;
void render(SDL_Renderer* renderer, position* red)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);	// Select the color for drawing. It is set to blue here.								
	SDL_RenderClear(renderer);// Clear the entire screen to our selected color.

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect redRect = { red->x,red->y,50,50 }; // {the x position, the y position, the width,height}
	SDL_RenderFillRect(renderer, &redRect);
	SDL_RenderPresent(renderer);

}
int events(position* red)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_WINDOWEVENT)
		{
			if(event.window.event==SDL_WINDOWEVENT_CLOSE) //https://wiki.libsdl.org/SDL_WindowEvent PREGUNTAR PQ ES EVENT.WINDOW.EVENT Y NO EVENT.WINDOW
			return 1; 
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym==SDLK_LEFT && red->x<width)
			{
				red->x-=10;
			}
			if(event.key.keysym.sym == SDLK_RIGHT && )
			{
				red->x += 10;
			}
			if (event.key.keysym.sym == SDLK_UP)
			{
				red->y -= 10;
			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				red->y += 10;
			}
		}
	}
}
#endif // !_HEADER_H_

