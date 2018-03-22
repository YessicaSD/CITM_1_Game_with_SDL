#ifndef _RENDER_H_
#define _RENDER_H_
void render()
{
	//SDL_Rect target;
	SDL_Rect target;

	g.backgroundScroll += SCROLL_SPEED;
	if (g.backgroundScroll >= g.backgroundWidth)
	{
		g.backgroundScroll = 0;
	}
	g.backgroundRec = { -g.backgroundScroll,0,g.backgroundWidth,SCREEN_HEIGHT};

	//Set black background
	SDL_SetRenderDrawColor(g.renderer, 0, 0, 0, 255);	// Select the color for drawing. It is set to black here.								
	SDL_RenderClear(g.renderer);// Clear the entire screen to our selected color.

	//Set tileMap
	SDL_RenderCopy(g.renderer, g.background, nullptr, &g.backgroundRec);
	g.backgroundRec.x += g.backgroundWidth;
	


	//Set ship1
	target = { g.CHARACTER_X, g.CHARACTER_Y, 10, 10 };
	SDL_RenderCopy(g.renderer, g.ship1, nullptr, &target);


	/*SDL_SetRenderDrawColor(g.renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(g.renderer, &g.redRect);*/





	SDL_RenderPresent(g.renderer);
}


#endif // !_RENDER_H_

