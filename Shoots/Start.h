#ifndef _START_H_
#define _START_H_
bool start()
{
	

	SDL_Init(SDL_INIT_VIDEO); //https://wiki.libsdl.org/SDL_Init


	//Initialize the window and render variable --
	window = SDL_CreateWindow("Last Resort", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC); // SDL_RENDERED_ACCELERATED DOES THE RENDERER WITH THE HARDWARE ACCELERATION


	// Load image lib --
	IMG_Init(IMG_INIT_PNG);
	image = IMG_Load("../Source/test.png");
	if (image == nullptr)
	{
		return false;
	}
	else
	{
		background = SDL_CreateTextureFromSurface(renderer, image);
		//SDL_QueryTexture(background, nullptr, nullptr,nullptr, nullptr);
	}
	SDL_Rect backgroundRec = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	SDL_Rect redRect = { CHARACTER_X,CHARACTER_Y,CHARACTER_WIDTH,CHARACTER_HEIGHT }; // {the x position, the y position, the width,height}
	SDL_Rect greenRect = { CHARACTER_X,CHARACTER_Y,20,20 }; // {the x position, the y position, the width,height}

	SDL_Event event;

	return true;
}
#endif // !_START_H_

