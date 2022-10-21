#include "UserMissile.h"
#include "Game.h"
#include <math.h>
#define PI 3.14159265


UserMissile::UserMissile(SDL_Texture* texture,int x, int y, SDL_Texture* smokeTexture) :GameObject(texture, x, y) {

	SmokeTexture = smokeTexture;
	//Initialize particles
	for (int i = 0; i < TOTAL_PARTICLES; ++i)
	{
		mPosX = xpos - 25 + (rand() % 25);
		mPosY = ypos + 10 +(rand() % 25);
		particles[i] = new Smoke(SmokeTexture,mPosX, mPosY);
	}
}

void UserMissile::Move() {

	if (xpos <= 864)
		this->xpos += 3;
	else
		alive = false;
}

UserMissile::~UserMissile()
{
	//Delete particles
	for (int i = 0; i < TOTAL_PARTICLES; ++i)
	{
		delete particles[i];
	}
}

void UserMissile::Render()
{
	//Show the dot
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &desRect);

	//Show particles on top of dot
	//Go through particles
	for (int i = 0; i < TOTAL_PARTICLES; ++i)
	{
		GameObject* gameObject = particles[i];
		//Delete and replace dead particles
		if (gameObject->Alive())
		{
			delete particles[i];
			mPosX = xpos - 25 + (rand() % 25);
			mPosY = ypos  + 10 + (rand() % 25);
			particles[i] = new Smoke(SmokeTexture,mPosX, mPosY);
		}
	}

	//Show particles
	for (int i = 0; i < TOTAL_PARTICLES; ++i)
	{
		GameObject* gameObject = particles[i];

		gameObject->Update();
		gameObject->Render();
	}
}


	
