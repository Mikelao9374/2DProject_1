#include <iostream>
#include <string>
#include <SDL.h>

#include "SDLcw.h"

using namespace std;

SDL_Texture* Character = NULL;
SDL_Rect CharacterPos;

SDL_Texture* cAttacking = NULL;
SDL_Rect cAttackingPos;

SDL_Texture* Enemy = NULL;
SDL_Rect EnemyPos;

SDL_Texture* eAttacking = NULL;
SDL_Rect eAttackingPos;

bool runningbool = true;

SDL_Texture* LoadTexture(string fileName, SDL_Renderer* renderer)
{
	SDL_Surface* SurfaceImage = NULL;
	SDL_Texture* TextureImage = NULL;
	string basePath = SDL_GetBasePath();

	SurfaceImage = SDL_LoadBMP((basePath + fileName).c_str());
	if (SurfaceImage == NULL) {
		cout << "Error while loading file: " << SDL_GetError() << endl;
		exit(1);
	}

	TextureImage = SDL_CreateTextureFromSurface(renderer, SurfaceImage);
	if (TextureImage == NULL) {
		cout << "Error while convert SDL_Surface into SDL_Texture:" << SDL_GetError() << endl;
		exit(1);
	}

	SDL_FreeSurface(SurfaceImage);

	return TextureImage;
}

void Init()
{
}

void EventHandler(SDL_Event* event)
{
	switch (event->type) {
		case SDL_QUIT:
			runningbool = false;
			break;
		case SDL_KEYDOWN:
			switch (event->key.keysym.sym) {
				case SDLK_UP:
					CharacterPos.y = CharacterPos.y - 5;
					break;
				case SDLK_DOWN:
					CharacterPos.y = CharacterPos.y + 5;
					break;
				case SDLK_LEFT:
					CharacterPos.x = CharacterPos.x - 5;
					break;
				case SDLK_RIGHT:
					CharacterPos.x = CharacterPos.x + 5;
					break;
				case SDLK_a:
					break;
			}
			break;
	}
}

void Render()
{
	SDL_SetRenderDrawColor(SDLcw::mRenderer, 0xcc, 0xcc, 0xcc, 0xff);
	SDL_RenderClear(SDLcw::mRenderer);
	SDL_RenderPresent(SDLcw::mRenderer);
}

int main(int argc,char* argv[])
{
	SDLcw::Init();
	SDL_Event event;

	while (runningbool == true) {
		while(SDL_PollEvent(&event))
			EventHandler(&event);

		Render();
	}
	
	SDL_Quit();
	return 0;
}
