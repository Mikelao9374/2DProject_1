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

//SDL_Texture* eAttacking = NULL;
//SDL_Rect eAttackingPos;

bool runningbool = true;

enum Key{
	Up = 0,
	Down,
	Left,
	Right
};
Key key = Up;

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
					key = Up;
					break;
				case SDLK_DOWN:
					CharacterPos.y = CharacterPos.y + 5;
					key = Down;
					break;
				case SDLK_LEFT:
					CharacterPos.x = CharacterPos.x - 5;
					key = Left;
					break;
				case SDLK_RIGHT:
					CharacterPos.x = CharacterPos.x + 5;
					key = Right;
					break;
				case SDLK_a:
					if (key == Up)
					{
						cAttackingPos.x = CharacterPos.x;
						cAttackingPos.y = CharacterPos.y - 5;
					}
					else if (key == Down)
					{
						cAttackingPos.x = CharacterPos.x;
						cAttackingPos.y = CharacterPos.y + 5;
					}
					else if (key == Left)
					{
						cAttackingPos.x = CharacterPos.x - 5;
						cAttackingPos.y = CharacterPos.y;
					}
					else if (key == Right)
					{
						cAttackingPos.x = CharacterPos.x + 5;
						cAttackingPos.y = CharacterPos.y;
					}
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

	Character = SDLli::LoadImage("Character.bmp", SDLcw::mRenderer);
	cAttacking = SDLli::LoadImage("cAttacking.bmp", SDLcw::mRenderer);
	Enemy = SDLli::LoadImage("Enemy.bmp", SDLcw::mRenderer);

	CharacterPos.x = 10;
	CharacterPos.y = 10;

	EnemyPos.x = 615;
	EnemyPos.y = 335;

	while (runningbool == true) 
	{
		while(SDL_PollEvent(&event))
		{
			EventHandler(&event);
			if (SDL_HasIntersection(&cAttackingPos, &EnemyPos) == SDL_TRUE)
			{
				exit(1);
			}
		}
		Render();
	}
	
	SDL_Quit();
	return 0;
}
