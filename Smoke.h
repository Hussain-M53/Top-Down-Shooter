#pragma once
#include "SDL.h" 
#include "GameObject.h"
#include "CreateTexture.h"
#include<iostream>
#include <stdio.h>

class Smoke : public GameObject {
private:
	int mFrame;
	CreateTexture* mTexture;
public:
	Smoke(SDL_Texture* texture,int x, int y);
	void Move();
	void Render();
	bool Alive();

};

