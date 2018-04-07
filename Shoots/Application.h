#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTexture.h"
#include "ModuleBackground.h"

#define NUM_MODULES 4


class Application
{
public:
	
	int i = 0;
	Module* modules[NUM_MODULES]= { nullptr };
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;

public:

	Application()
	{
		modules[0] = window = new ModuleWindow();
		modules[1] = render = new ModuleRender();
		modules[2] = input = new ModuleInput();
		modules[3] = textures = new ModuleTextures();
	}


	// INIT all modules
	bool Init()
	{
		for (int i = 0; i < NUM_MODULES; ++i)
			modules[i]->Init();
		return true;
	}

	update_status Update() {

		update_status ret = UPDATE_CONTINUE;
		for (i = 0; i<NUM_MODULES; ++i)
		{
			ret = modules[i]->PreUpdate();

		}

		for (i = 0; i<NUM_MODULES; ++i)
		{
			ret = modules[i]->Update();
		
		}

		for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
			ret = modules[i]->PostUpdate();


		return ret;
	}

	bool CleanUp()
	{
		bool ret = true;
		for (i = 0; i<NUM_MODULES; ++i)
		{
			modules[i]->CleanUp();
		}
		return ret;
	}
};

// Global var made extern for Application ---
extern Application* App;
#endif // __APPLICATION_H__
