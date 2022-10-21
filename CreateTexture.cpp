#include "CreateTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

CreateTexture::CreateTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

SDL_Texture* CreateTexture::LoadTexture(const char* filename) {
	SDL_Surface* tempSurface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer,tempSurface);
	if (texture == NULL) {
		printf("Unable to create texture from %s! SDL Error: %s\n", filename, SDL_GetError());
	}
	else {
		mWidth = tempSurface->w;
		mHeight = tempSurface->h;
	}
	SDL_FreeSurface(tempSurface);
	
	mTexture = texture;
	return texture;
}

int CreateTexture::getWidth()
{
	return mWidth;
}

int CreateTexture::getHeight()
{
	return mHeight;
}