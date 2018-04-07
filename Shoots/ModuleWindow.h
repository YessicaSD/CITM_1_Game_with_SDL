#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

#include "Module.h"

struct SDL_Window;
struct SDL_Surface;

class ModuleWindow : public Module
{
public:
	//The window we'll be rendering to
	SDL_Window * window = nullptr;

	//The surface contained by the window
	SDL_Surface* screen_surface = nullptr;

public:

	ModuleWindow();

	// Destructor
	virtual ~ModuleWindow();

	// Called before quitting
	bool Init() {
		//Init SDL window & surface---------------------------
		bool ret = true;
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			//SDL_VIDEO could not initialize! SDL_Error -------------------------
			ret = false;
		}
		else
		{
			Uint32 flags = SDL_WINDOW_SHOWN;
			if (WIN_FULLSCREEN == true)
				flags |= SDL_WINDOW_FULLSCREEN;

			if (WIN_BORDERLESS == true)
				flags |= SDL_WINDOW_BORDERLESS;

			if (WIN_RESIZABLE == true)
				flags |= SDL_WINDOW_RESIZABLE;

			if (WIN_FULLSCREEN_DESKTOP == true)
				flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
			window = SDL_CreateWindow("Last Resort", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
			if (window == NULL)
			{
				//Window could not be created! SDL_Error: %s\n", SDL_GetError());
				ret = false;
			}
			else
			{
				//Get window surface
				screen_surface = SDL_GetWindowSurface(window);
			}
		}
		return ret;
	}

	// Called before quitting
	bool CleanUp()
	{
		//Destroying SDL window and quitting all SDL systems------------------

		//Destroy window
		if (window != NULL)
			SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();
		return true;
	}


};

#endif // __ModuleWindow_H__
