#ifndef _RENDER_H_
#define _RENDER_H_
void render()
{

	//Set black background
	SDL_SetRenderDrawColor(g.renderer, 255, 255, 255, 255);	// Select the color for drawing. It is set to black here.								
	SDL_RenderClear(g.renderer);// Clear the entire screen to our selected color.

	//Set tilemap 
	SDL_RenderCopy(g.renderer, g.background, NULL, &g.backgroundRec);

	//Set background
	SDL_SetRenderDrawColor(g.renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(g.renderer, &g.redRect);

	SDL_RenderPresent(g.renderer);
}


#endif // !_RENDER_H_

