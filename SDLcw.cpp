#include"SDLcw.h"

SDL_Window* SDLcw::mWindow = NULL;
SDL_Renderer* SDLcw::mRenderer = NULL;

SDLcw::SDLcw()
{
}

SDLcw::~SDLcw()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
}

void SDLcw::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	mWindow = SDL_CreateWindow("2DProject_1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, SDL_WINDOW_SHOWN);

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
}
