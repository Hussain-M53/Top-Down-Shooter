#include "SDL.h" 
#include <stdio.h>
#pragma once

class CreateTexture {
protected:
	int mWidth;
	int mHeight;
	SDL_Texture* mTexture;

public:
	CreateTexture();
	SDL_Texture* LoadTexture(const char* filename);
	int getWidth();
	int getHeight();
};