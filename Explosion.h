#pragma once
#include "SDL.h" 
#include "GameObject.h"
#include<iostream>
#include <stdio.h>

class Explosion : public GameObject {
	int mFrame;
	double angle;

public:
	Explosion(SDL_Texture* texture,int x, int y);
	void Move();
	void Render();
	bool Alive();
};

