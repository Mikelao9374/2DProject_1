#include<iostream>
#include<SDL2/SDL.h>
#include<SDLss.h>

class SDLcw
{
	public:
		SDLcw();
		~SDLcw();
		
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
}
