#include "GameObject.h"
#include "Game.h"
#include "CreateTexture.h"


	GameObject::GameObject(SDL_Texture* texture,int x,int y )
	{
		objTexture = texture;
		xpos = x;
		ypos = y;
		srcRect.h = 64;
		srcRect.w = 64;
		desRect.w = 64;
		desRect.h = 64;
		desRect.x = x;
		desRect.y = y;
		srcRect.x = 0;
		srcRect.y = 0;
		count_lives = 1;
	}

	GameObject:: ~GameObject() {}
	void GameObject::Update() {

		srcRect.x = srcx;
		srcRect.y = srcy;
		desRect.x = xpos;
		desRect.y = ypos;
	}


	void GameObject::Render() {
		SDL_RenderCopy(Game::renderer,objTexture, &srcRect, &desRect);
	}

	bool GameObject::Alive() {
		return alive;
	}

	void GameObject::Move() {
	
	}

	void GameObject::Dodge()
	{
	}

	void GameObject::Translate(int x,int y) {

	}


