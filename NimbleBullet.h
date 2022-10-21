#pragma once
#include "SDL.h" 
#include "GameObject.h"
#include<iostream>
#include <stdio.h>

class NimbleBullet : public GameObject {
public:
	NimbleBullet(SDL_Texture* texture,int x, int y);
	void Move();
};
