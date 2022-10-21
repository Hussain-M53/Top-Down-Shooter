#pragma once
#include "SDL.h" 
#include "GameObject.h"
#include<iostream>
#include <stdio.h>

class UserPlane : public GameObject {
	float friction = 0.96;
	float tx;
	float ty;
public:
	UserPlane(SDL_Texture* texture,int x, int y);
	void Translate(int x,int y);
	void Move();
};

