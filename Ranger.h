#pragma once
#include "SDL.h" 
#include "GameObject.h"
#include<iostream>
#include <stdio.h>

class Ranger: public GameObject {
public:

	Ranger(SDL_Texture* texture,int x, int y);
	void Move();
	void Dodge();
};

