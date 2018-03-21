#ifndef _GLOBALS_H_
#define _GLOBALS_H_


#define distanceMovement 10
int SCREEN_WIDTH = 320;
int SCREEN_HEIGHT = 224;

int SCROLL_SPEED = 5;

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


SDL_Window* window = nullptr; /* Declare a window*/
SDL_Renderer* renderer = nullptr; // Declare a render
SDL_Texture*background = nullptr;
SDL_Surface* image = nullptr;


#endif // !_GLOBALS_H_

