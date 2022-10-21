#pragma once
#include "SDL.h" 
#include "GameObject.h"
#include<iostream>
#include <stdio.h>

class nimble : public GameObject {
public:
	nimble(SDL_Texture* texture, int x, int y);
	void Move();
	void Dodge();
};

