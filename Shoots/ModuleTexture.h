#ifndef __ModuleTextures_H__
#define __ModuleTextures_H__


#include "Globals.h"
#include "Application.h"
#include "Module.h"
#include "SDL/include/SDL.h"
#include "SDL/include/SDL_image.h"
#pragma comment(lib,"SDL/SDL2_image.lib")

#define MAX_TEXTURES 50

struct SDL_Texture;

class ModuleTextures : public Module
{
public:
	SDL_Texture * textures[MAX_TEXTURES];
	uint last_texture = 0;
	SDL_Texture* background = nullptr;
	SDL_Texture * ship1 = nullptr;

public:
	ModuleTextures()
	{
		for (uint i = 0; i < MAX_TEXTURES; ++i)
			textures[i] = nullptr;
	}
	~ModuleTextures();

	bool Init()
	{
		//Init Image library");
		bool ret = true;

		// load support for the PNG image format
		int flags = IMG_INIT_PNG;
		int init = IMG_Init(flags);

		if ((init & flags) != flags)
		{
			//Could not initialize Image lib. 
			ret = false;
		}

		return ret;
	}
	bool CleanUp() 
	{
		//Freeing textures and Image library

		for (uint i = 0; i < MAX_TEXTURES; ++i)
			if (textures[i] != nullptr)
				SDL_DestroyTexture(textures[i]);

		IMG_Quit();
		return true;
	}

	SDL_Texture* const Load(const char* path) {

		SDL_Texture* texture = NULL;
		SDL_Surface* surface = IMG_Load(path);
		if (surface == NULL)
		{
			//Could not load surface with path: %s. IMG_Load: %s", path, IMG_GetError());
		}
		else
		{
			texture = SDL_CreateTextureFromSurface(App->render->renderer, surface);

			if (texture == NULL)
			{
				//"Unable to create texture from surface! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				textures[last_texture++] = texture;
			}

			SDL_FreeSurface(surface);
		}

		return texture;

	}


	

};

#endif // __ModuleTextures_H__
