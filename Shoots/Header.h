#ifndef _HEADER_H_
#define _HEADER_H_
int width = 1920;
int height = 1010;
typedef struct
{
	int x;
	int y;
}position;
void render(SDL_Renderer* renderer, position* red)
{

}
void shoot(SDL_Renderer* renderer, position*green)
{
	while ((green->x)<width)
	{
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_Rect redRect = { green->x,green->y,20,20 }; // {the x position, the y position, the width,height}
		SDL_RenderFillRect(renderer, &redRect);
		green->x += 1;
		SDL_RenderPresent(renderer);
	}

}
int events(position* red, position*green,SDL_Renderer* renderer)
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
			if (event.key.keysym.sym==SDLK_LEFT && red->x >0 )
			{

				red->x-=1;
			}
			if(event.key.keysym.sym == SDLK_RIGHT && (red->x)<width-50 )
			{
				red->x += 10;
			}
			if (event.key.keysym.sym == SDLK_UP && (red->y)>0 )
			{
				red->y -= 10;
			}
			if (event.key.keysym.sym == SDLK_DOWN && (red->y)<height - 50 )
			{
				red->y += 10;
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
				green->x = red->x;
				green->y = red->y;
				shoot(renderer, green);
			}
		}
	}
	
}

#endif // !_HEADER_H_

