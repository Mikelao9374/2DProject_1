#include <iostream>
#include <SDL2/SDL.h>

class SDLcw
{
	public:
		SDLcw();
		~SDLcw();

		static void Init();
		
		static SDL_Window* mWindow;
		static SDL_Renderer* mRenderer;
};
