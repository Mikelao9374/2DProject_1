#include <iostream>
#include <string>
#include <SDL.h>

#include "SDLcw.h"
#include "SDLli.h"

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
