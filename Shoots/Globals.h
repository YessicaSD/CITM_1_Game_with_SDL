#ifndef _GLOBALS_H_
#define _GLOBALS_H_


#define distanceMovement 10
int SCREEN_WIDTH = 320;
int SCREEN_HEIGHT = 224;

int SCROLL_SPEED = 1;

int CHARACTER_SPEED = 10;
int CHARACTER_WIDTH = 10;
int CHARACTER_HEIGHT = 10;
int CHARACTER_X = SCREEN_WIDTH/2;
int CHARACTER_Y = SCREEN_HEIGHT/2;

int NUM_SHOTS = 32;
int SHOOT_SPEED = 5;


int escape = 0;

bool shoot = false;


bool leftPress = false;
bool rightPress = false;
bool upPress = false;
bool downPress = false;

struct globals
{
	int backgroundScroll = 0;
	int backgroundWidth = 4408;
	int backgroundHeight = 224;
	SDL_Window* window = nullptr; /* Declare a window*/
	SDL_Renderer* renderer = nullptr; // Declare a render
	SDL_Texture* background = nullptr;
	SDL_Texture * ship1 = nullptr;
	SDL_Surface* image = nullptr;

	SDL_Rect backgroundRec = { backgroundScroll,0,backgroundWidth,backgroundHeight};

	SDL_Rect redRect = { CHARACTER_X,CHARACTER_Y,CHARACTER_WIDTH,CHARACTER_HEIGHT }; // {the x position, the y position, the width,height}
	SDL_Rect greenRect = { CHARACTER_X,CHARACTER_Y,20,20 }; // {the x position, the y position, the width,height}

	SDL_Event event;
}g;



#endif // !_GLOBALS_H_

