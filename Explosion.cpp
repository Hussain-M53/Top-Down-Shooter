#include "Explosion.h"
#include <math.h>
#include "CreateTexture.h"



Explosion::Explosion(SDL_Texture* texture, int x, int y):GameObject(texture,x,y)
{
	srcRect.h = 64;
	srcRect.w = 64;
	desRect.w = 64;
	desRect.h = 64;
	//Initialize animation
	mFrame = rand() % 50;
	angle = 0;
}

void Explosion::Move() {
		this->ypos-=1 ;
		this->xpos += 2 * sin(angle);
		angle += 0.5;
	
}

void Explosion::Render() {
	//Show image
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &desRect);

	//Animate
	mFrame++;
}

bool Explosion::Alive() {
	return mFrame < 50;
}