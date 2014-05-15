#include "SDLli.h"

SDL_Texture* SDLli::LoadImage(string fileName, SDL_Renderer* renderer)
{
	SDL_Surface* SurfaceImage;
	SDL_Texture* TextureImage;
	string basePath = SDL_GetBasePath();

	SurfaceImage = SDL_LoadBMP((basePath + fileName).c_str());
	if(SurfaceImage == NULL)
	{
		cout << "SDL ERROR:" << SDL_GetError() << endl;
		exit(1);
	}
	
	TextureImage = SDL_CreateTextureFromSurface(renderer, SurfaceImage);
	if(TextureImage == NULL)
	{
		cout << "SDL ERROR:" << SDL_GetError() << endl;
		exit(1);
	}
	
	SDL_FreeSurface(SurfaceImage);
	return TextureImage;
}	
