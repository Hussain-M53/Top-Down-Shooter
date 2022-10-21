#pragma once
#include "SDL.h" 
#include "GameObject.h"
#include<iostream>
#include <stdio.h>


class UserBullet : public GameObject {
public:
	UserBullet(SDL_Texture* texture,int x, int y);
	void Move();
};

