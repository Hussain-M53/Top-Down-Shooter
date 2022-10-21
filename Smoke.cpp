#include "Smoke.h"

Smoke::Smoke(SDL_Texture* texture,int x, int y) :GameObject(texture, x, y) {

	srcRect.h = 15;
	srcRect.w = 15;
	desRect.w = 15;
	desRect.h = 15;
	//Initialize animation
	mFrame = rand() % 5;
}

void Smoke::Move() {
	this->xpos -= 5;
}

void Smoke::Render() {
	//Show image
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &desRect);

	//Animate
	mFrame++;
}

bool Smoke::Alive() {
	return mFrame > 10;
}
