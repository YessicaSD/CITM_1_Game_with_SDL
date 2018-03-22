#ifndef _START_H_
#define _START_H_
bool start()
{
	

	SDL_Init(SDL_INIT_VIDEO); //https://wiki.libsdl.org/SDL_Init


	//Initialize the window and render variable --
	g.window = SDL_CreateWindow("Last Resort", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	g.renderer = SDL_CreateRenderer(g.window, -1, SDL_RENDERER_PRESENTVSYNC); // SDL_RENDERED_ACCELERATED DOES THE RENDERER WITH THE HARDWARE ACCELERATION


	// Load image lib --

	//Load background
	IMG_Init(IMG_INIT_PNG);
	g.image = IMG_Load("../Sources/TileMap1.png");
	if (g.image == nullptr)
	{
		return false;
	}
	else
	{
		g.background = SDL_CreateTextureFromSurface(g.renderer, g.image);
	}

	g.backgroundRec = { g.backgroundScroll,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	


	//Load ship1
	g.image = IMG_Load("../Sources/SpaceShip_player1.png");
	if (g.image == nullptr)
	{
		return false;
	}
	else
	{
		g.ship1 = SDL_CreateTextureFromSurface(g.renderer, g.image);
	}

	g.backgroundRec = { g.backgroundScroll,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	return true;
}
#endif // !_START_H_

