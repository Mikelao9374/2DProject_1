#include "SDLli.h"

SDLli::SDLli(string fileName, SDL_Renderer* renderer)
{
	SurfaceImage = SDL_LoadBMP((basePath + filename).c_str());
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
