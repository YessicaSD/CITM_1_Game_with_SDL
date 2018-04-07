#include "SDL/include/SDL.h"
#include "SDL/include/SDL_image.h"
#pragma comment(lib, "SDL/SDL2.lib")
#pragma comment(lib, "SDL/SDL2main.lib")
#pragma comment(lib,"SDL/SDL2_image.lib")

#include "MemLeaks.h"
#include "Application.h"
#include "Globals.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleWindow.h"
#include "ModuleBackground.h"
#include "ModuleTexture.h"


enum main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};
Application* App = nullptr;

int main(int argc, char* argv[])
{
	ReportMemoryLeaks();
	int main_return= EXIT_FAILURE;
	main_states state = MAIN_CREATION;
	
	while (state!=MAIN_EXIT)
	{
		switch (state)
		{
		case MAIN_CREATION:
		{
			//("\nApplication Creation --------------");
			App = new Application();
			state = MAIN_START;
		}
			break;


		case MAIN_START:
			// Application Start--------------------
			start();
			if (App->Init() == false)
			{
				//Application Init exits with error -----
				state = MAIN_EXIT;
			}
			else
			{
				state = MAIN_UPDATE;
			}
			break;


		case MAIN_UPDATE:
		{
			//Create a new variable enum called update_status -------
			update_status status = App->Update();
			if (status == UPDATE_ERROR)
			{
				//Application Init exits with error -----
				state = MAIN_EXIT;
			}
			else if (status == UPDATE_STOP)
			{
				state = MAIN_FINISH;
			}
		}break;



		case MAIN_FINISH:

			state = MAIN_EXIT;
			main_return = EXIT_SUCCESS;
			break;
		
		}
	
		
		

		

	}
	

	return main_return;
}