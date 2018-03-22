#ifndef _CHECKINPUT_H_
#define _CHECKINPUT_H_
bool checkInput()
{
	while (SDL_PollEvent(&g.event))
	{
		if (g.event.type == SDL_QUIT)
		{
			return false;
		}
		if (g.event.type == SDL_KEYDOWN)
		{
			if (g.event.key.keysym.sym == SDLK_LEFT)
			{
				leftPress = true;

			}
			if (g.event.key.keysym.sym == SDLK_RIGHT)
			{
				rightPress = true;
			}
			if (g.event.key.keysym.sym == SDLK_UP)
			{
				upPress = true;
			}
			if (g.event.key.keysym.sym == SDLK_DOWN)
			{
				downPress = true;
			}
			if (g.event.key.keysym.sym == SDLK_ESCAPE)
			{
				return false;
			}

		}
		if (g.event.type == SDL_KEYUP)
		{
			if (g.event.key.keysym.sym == SDLK_SPACE)
			{
				g.greenRect.x = g.redRect.x;
				g.greenRect.y = g.redRect.y;
				shoot = true;

			}
			if (g.event.key.keysym.sym == SDLK_LEFT)
			{
				leftPress = false;

			}
			if (g.event.key.keysym.sym == SDLK_RIGHT)
			{
				rightPress = false;
			}
			if (g.event.key.keysym.sym == SDLK_UP)
			{
				upPress = false;
			}
			if (g.event.key.keysym.sym == SDLK_DOWN)
			{
				downPress = false;
			}

		}
	}// fin de bucle
}
#endif // !_CHECKINPUT_H_

