#include <iostream>
#include <string>
#include <SDL2/SDL.h>

using namespace std;

class SDLcw
{
	public:
		SDLcw();
		~SDLcw();

		static void Init();
		
		static SDL_Window* mWindow;
		static SDL_Renderer* mRenderer;
};
