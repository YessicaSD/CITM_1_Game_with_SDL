#ifndef _MODULERENDER_H_
#define _MODULERENDER_H_
#include "Application.h"
#include "ModuleRender.h"
#include "Module.h"


class ModuleRender : public Module
{
public:
	SDL_Renderer * renderer = nullptr; // Declare a render

public:


	bool Init()
	{
		bool ret = true;
		//Creating Renderer context--------------
		Uint32 flags = 0;

		if (REN_VSYNC == true)
		{
			flags |= SDL_RENDERER_PRESENTVSYNC;
		}

		renderer = SDL_CreateRenderer(App->window->window, -1, flags);

		if (renderer == NULL)
		{
			//Renderer could not be created!
			ret = false;
		}

		return ret;
	}

	update_status PreUpdate()
	{
		SDL_RenderClear(renderer);
		return update_status::UPDATE_CONTINUE;
	}

	update_status Update()
	{
		return update_status::UPDATE_CONTINUE;
	}

	update_status PostUpdate()
	{
		
		return update_status::UPDATE_CONTINUE;
	}

	bool CleanUp()
	{
		
		return true;
	}
};



#endif // !_MODULERENDER_H_

