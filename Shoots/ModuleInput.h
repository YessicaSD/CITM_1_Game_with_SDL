#ifndef _MODULECHECKINPUT_H_
#define _MODULECHECKINPUT_H_

#include "Module.h"
#include "Globals.h"
class ModuleInput : public Module
{
public:
	ModuleInput() {};
	~ModuleInput() {};

public:
	const Uint8 *keyboard = nullptr;

public:
	bool Init()
	{
		//LOG("Init SDL input event system");
		bool ret = true;
		SDL_Init(0);

		if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
		{
			//LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
			ret = false;
		}

		return ret;
	}

	update_status PreUpdate()
	{
		//LOG("Dummy PreUpdate!");
		SDL_PumpEvents();

		keyboard = SDL_GetKeyboardState(NULL);

		if (keyboard[SDL_SCANCODE_ESCAPE])
		{
			return update_status::UPDATE_STOP;
		}

		return update_status::UPDATE_CONTINUE;
	}


	bool CleanUp()
	{
		//LOG("Module CleanUp!");
		return true;
	}
};

 
#endif // !_MODULECHECKINPUT_H_

