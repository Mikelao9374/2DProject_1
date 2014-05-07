#include"SDLcw.h"

SDLcw::SDLcw()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	mWindow = SDL_CreateWindow("2DProject_1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, SDL_WINDOW_SHOWN);
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
}

SDLcw::~SDLcw()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
}
