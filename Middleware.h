#pragma once
#include "GameObject.h"
#include "CreateTexture.h"
#include <vector>


struct Middleware {

	Middleware();
	static void render(vector<GameObject*> &list);
	static void clean(vector<GameObject*> &list);
	static void moveAndUpdate(vector<GameObject*> &list, int nSpeedCount);
	static void animateOnce(vector<GameObject*> &list);
	static void animateRepeat(vector<GameObject*> &list);
	static void createExplosion(GameObject* object, SDL_Texture* ExplosionTexture, vector<GameObject*> &explosion_list);

};