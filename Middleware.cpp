#include "Middleware.h"
#include "Explosion.h"
#include "SDL.h" 
#include "CreateTexture.h"

Middleware::Middleware() {}


void Middleware::render(vector<GameObject*> &list) {
	for (int i = 0; i < list.size(); i++) {
		GameObject* gameObject;
		gameObject = list.at(i);
		gameObject->Render();
	}
}

void Middleware::clean(vector<GameObject*> &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list.at(i)->Alive() == false)
		{
			delete list.at(i);
			list.erase(list.begin() + i);
		}
	}
}

void Middleware::moveAndUpdate(vector<GameObject*> &list, int nSpeedCount)
{
	for (int i = 0; i < list.size(); i++) {
		GameObject* gameObject;
		gameObject = list.at(i);
		if (nSpeedCount % 100) {
			gameObject->Move();
		}
		gameObject->Update();
	}
}

void Middleware::animateOnce(vector<GameObject*> &list) {

	for (int i = 0; i < list.size(); i++) {
		GameObject* gameObject = list.at(i);
		gameObject->srcy += 64;
		if (gameObject->srcy % 256 == 0) gameObject->srcy = 192;
	}
}

void Middleware::animateRepeat(vector<GameObject*> &list) {

	for (int i = 0; i < list.size(); i++) {
		GameObject* gameObject = list.at(i);
		gameObject->srcy += 64;
		if (gameObject->srcy % 192 == 0) gameObject->srcy = 0;
	
	}
}

void Middleware::createExplosion(GameObject* object, SDL_Texture* ExplosionTexture, vector<GameObject*> &explosion_list) {
	for (int i = 0; i < 15; i++) {
		double randomX = rand() % 64;
		double randomY = rand() % 30 - 15;
		GameObject* explosion = new Explosion(ExplosionTexture, object->xpos - randomX, object->ypos - randomY);
		explosion_list.insert(explosion_list.begin(), explosion);
	}
}
