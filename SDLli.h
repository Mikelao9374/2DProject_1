#include <iostream>
#include <SDL2/SDL.h>
#include <string>

class SDLli
{
	public:
		SDLli(string fileName, SDL_Renderer* renderer);
		~SDLli();

		SDL_Surface* SurfaceImage;
		SDL_Texture* TextureImage;
		string basePath = SDL_GetBasePath();
}
