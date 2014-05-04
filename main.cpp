#include<iostream>
#include<SDL2/SDL.h>
#include<string>

using namespace std;

SDL_Window* mWindow = NULL;
SDL_Renderer* mRenderer = NULL;

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
	if(SurfaceImage == NULL);
	{
		cout << "SDL ERROR:" << SDL_GetError() << endl;
		exit(1);
	}
	TextureImage = SDL_CreateTextureFromSurface(renderer, SurfaceImage);
	if(TextureImage == NULL)
	{
		cout << "SDL_ERROR:" << SDL_GetError() << endl;
		exit(1);
	}
	SDL_FreeSurface(SurfaceImage);
	return TextureImage;
}

void Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	mWindow = SDL_CreateWindow("2DProject_1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, SDL_WINDOW_SHOWN);
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

	Character = LoadTexture("Character.bmp", mRenderer);
	cAttacking = LoadTexture("cAttacking.bmp", mRenderer);
	Enemy = LoadTexture("Enemy.bmp", mRenderer);
	eAttacking = LoadTexture("eAttacking.bmp", mRenderer);

	CharacterPos.x = 10;
	CharacterPos.y = 10;
	CharacterPos.w = 80;
	CharacterPos.y = 100;
}

void EventHandler(SDL_Event* event)
{
	switch(event->type)
	{
		case SDL_QUIT:
			runningbool = false;
			break;
		case SDL_KEYDOWN:
			switch(event->key.keysym.sym)
			{
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
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderClear(mRenderer);
	SDL_RenderCopy(mRenderer, Character, NULL, &CharacterPos);
	SDL_RenderPresent(mRenderer);
}

int main(int argc,char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* mWindow = NULL;
	mWindow = SDL_CreateWindow("Testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, SDL_WINDOW_SHOWN);
	SDL_Delay(3000);
	SDL_Quit();
	return 0;
}
