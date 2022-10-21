#pragma once
#include "Game.h"
#include <stdio.h>

class GameObject {
protected:
	SDL_Texture* objTexture;
	SDL_Rect srcRect, desRect;

public:
	bool alive= true;
	double xpos;
	double ypos;
	int srcx = 0;
	int srcy = 0;
	int count_lives;
	GameObject(SDL_Texture* texture,int x,int y);
	~GameObject();
	virtual  bool Alive();
	virtual void Update();
	virtual void Move();
	virtual void Dodge();
	virtual void Render();
	virtual void Translate(int x,int y);
};