#pragma once
#include "SDL.h" 
#include "GameObject.h"
#include<iostream>
#include <stdio.h>
#include "Smoke.h"


class UserMissile : public GameObject {
private:
	//The particles
	const int TOTAL_PARTICLES = 20;
	Smoke* particles[20];

	//The X and Y offsets of the dot
	int mPosX, mPosY;
	SDL_Texture* SmokeTexture;

public:
	UserMissile(SDL_Texture* texture,int x, int y,SDL_Texture* smokeTexture);
	~UserMissile();
	void Move();
	void Render();
};

