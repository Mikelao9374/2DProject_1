#include <iostream>
#include <SDL2/SDL.h>
#include <string>

#ifndef SDLLI_H
#define SDLLI_H

using namespace std;

class SDLli
{
	public:
		SDLli(){};
		~SDLli();

		static SDL_Texture* LoadImage(string filename, SDL_Renderer* renderer);
};

#endif
