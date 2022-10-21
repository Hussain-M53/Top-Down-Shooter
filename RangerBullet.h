#pragma once
#include "SDL.h" 
#include "GameObject.h"
#include<iostream>
#include <stdio.h>

class RangerBullet : public GameObject {
	double angle;
	int angleDegree;
	int movX, movY;
public:
RangerBullet(SDL_Texture* texture,int x, int y, int playerX, int playerY);
void Move();
void Render();
};