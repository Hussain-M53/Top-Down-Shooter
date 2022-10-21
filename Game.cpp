#include "Game.h"
#include "GameObject.h"
#include "nimble.h"
#include "UserPlane.h"
#include <SDL.h>
#include <SDL_image.h>
#include "CreateTexture.h"
#include <vector>
#include "Ranger.h"
#include "RangerBullet.h"
#include "NimbleBullet.h"
#include "UserBullet.h"
#include "UserMissile.h"
#include "Smoke.h"
#include "Explosion.h"
#include <cstdlib>
#include <iostream>
#include "SDL_ttf.h"
#include <sstream>
#include "Middleware.h"

using namespace std;

Game::Game() {
	window = NULL;
	isRunning = false;
}


Game::~Game() {}

SDL_Texture* playerTexture;
SDL_Rect srcR, desR;
int count = 0;
int missile_limit = 10;
int score = 0;
SDL_Renderer* Game::renderer = nullptr;
SDL_Texture* Missiles_Message;
SDL_Texture* Score_Message;
SDL_Surface* surfaceMessage;
GameObject* player;

CreateTexture CreatePlayer;
CreateTexture CreateNimble;
CreateTexture CreateRanger;
CreateTexture CreateSmoke;
CreateTexture CreateExplosion;
CreateTexture CreateUserBullet;
CreateTexture CreateUserMissile;
CreateTexture CreateRangerBullet;
CreateTexture CreateNimbleBullet;

SDL_Texture* PlayerTexture;
SDL_Texture* NimbleTexture;
SDL_Texture* RangerTexture;
SDL_Texture* SmokeTexture;
SDL_Texture* ExplosionTexture;
SDL_Texture* UserBulletTexture;
SDL_Texture* UserMissileTexture;
SDL_Texture* RangerBulletTexture;
SDL_Texture* NimbleBulletTexture;

GameObject* userBullet;
GameObject* userMissile;
vector<GameObject*> ranger_list;
vector<GameObject*> nimble_list;
vector<GameObject*> user_bullet_list;
vector<GameObject*> nimble_bullet_list;
vector<GameObject*> ranger_bullet_list;
vector<GameObject*> user_missile_list;
vector<GameObject*> explosion_list;


int nSpeedCount = 0;

void Game::loadTextures() {
	PlayerTexture = CreatePlayer.LoadTexture("Images/user_plane.png");
	NimbleTexture = CreateNimble.LoadTexture("Images/nimble.png");
	RangerTexture = CreateRanger.LoadTexture("Images/ranger.png");
	SmokeTexture = CreateSmoke.LoadTexture("Images/smoke_small.png");
	ExplosionTexture = CreateExplosion.LoadTexture("Images/explosion.png");
	UserBulletTexture = CreateUserBullet.LoadTexture("Images/user_bullet.png");
	UserMissileTexture = CreateUserMissile.LoadTexture("Images/user_missile.png");
	RangerBulletTexture = CreateRangerBullet.LoadTexture("Images/ranger_bullet.png");
	NimbleBulletTexture = CreateNimbleBullet.LoadTexture("Images/nimble_bullet.png");
}

void Game::initialize(const char* title, int x, int y, int width, int height, bool fullscrean) {

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		isRunning = false;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow(title, x, y, width, height, 0);
		TTF_Init();
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			isRunning = false;
		}
		else
		{
			//Get window surface
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer) {
				SDL_SetRenderDrawColor(renderer, 76, 103, 147 , 255);
			}
			isRunning = true;
		}
		Game::loadTextures();
		player = new UserPlane(PlayerTexture,50, 50);
	}
}

void Game::updateScore(TTF_Font* SpaceFont, SDL_Rect& Missile_rect, SDL_Rect& Score_rect) {
	SDL_Color Color = { 255, 255, 255 ,255 };
	stringstream ss;
	string display_missile;
	ss << missile_limit;
	ss >> display_missile;

	string missilesLeftMessage = "Missiles Left: " + display_missile;
	surfaceMessage = TTF_RenderText_Solid(SpaceFont, missilesLeftMessage.c_str(), Color);
	Missiles_Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_QueryTexture(Missiles_Message, NULL, NULL, &Missile_rect.w, &Missile_rect.h);

	stringstream ss2;
	string display_score;
	ss2 << score;
	ss2 >> display_score;

	string displayMessageScore = "Your Score: " + display_score;
	surfaceMessage = TTF_RenderText_Solid(SpaceFont, displayMessageScore.c_str(), Color);
	Score_Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	

	SDL_QueryTexture(Score_Message, NULL, NULL, &Score_rect.w, &Score_rect.h);
}

void Game::handleEvents() {

	SDL_Event event;

	while (SDL_PollEvent(&event) != 0) {

		if (event.type == SDL_QUIT)
			isRunning = false;
		else if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				userBullet = new UserBullet(UserBulletTexture,player->xpos, player->ypos);
				user_bullet_list.insert(user_bullet_list.begin(), userBullet);
				break;
			case SDLK_b:
				if (missile_limit > 0) {
					userMissile = new UserMissile(UserMissileTexture,player->xpos, player->ypos,SmokeTexture);
					user_missile_list.insert(user_missile_list.begin(), userMissile);
					missile_limit--;
				}
			}
		}
	}
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_UP]) {
		player->Translate(0, -4);
	}
	if (currentKeyStates[SDL_SCANCODE_DOWN]) {
		player->Translate(0, 4);
	}
	if (currentKeyStates[SDL_SCANCODE_LEFT]) {
		player->Translate(-5, 0);
	}
	if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
		player->Translate(5, 0);
	}
}


void Game::render(TTF_Font* SpaceFont, SDL_Rect& Missile_rect, SDL_Rect& Score_rect) {

	updateScore(SpaceFont, Missile_rect, Score_rect);

	SDL_RenderClear(renderer);
	if (player->alive == true) {
		player->Move();
		player->Render();
	}

	Middleware::render(ranger_list);
	Middleware::render(nimble_list);
	Middleware::render(ranger_bullet_list);
	Middleware::render(nimble_bullet_list);
	Middleware::render(user_bullet_list);
	Middleware::render(user_missile_list);
	Middleware::render(explosion_list);

	SDL_RenderCopy(renderer, Missiles_Message, NULL, &Missile_rect);
	SDL_RenderCopy(renderer, Score_Message, NULL, &Score_rect);
	SDL_Delay(3);
	SDL_RenderPresent(renderer);
}

void Game::handleListChanges() {
	nSpeedCount++;

	if (nSpeedCount % 800 == 0)
	{
		int random = 100 + rand() % 450;

		int randomSelect = rand() % 2;
		if (randomSelect == 0) {
			GameObject* ranger_player = new Ranger(RangerTexture, 800, random);
			ranger_list.insert(ranger_list.begin(), ranger_player);
		}
		else {
			GameObject* nimble_player = new nimble(NimbleTexture, 800, random);
			nimble_list.insert(nimble_list.begin(), nimble_player);
		}

	}

	if (nSpeedCount % 600 == 0)
	{
		for (int i = 0; i < ranger_list.size(); i++) {
			GameObject* ranger_list_object = ranger_list.at(i);
			GameObject* bullet = new RangerBullet(RangerBulletTexture, ranger_list_object->xpos, ranger_list_object->ypos, player->xpos, player->ypos);
			ranger_bullet_list.insert(ranger_bullet_list.begin(), bullet);
		}

		for (int i = 0; i < nimble_list.size(); i++) {
			GameObject* nimble_list_object = nimble_list.at(i);
			GameObject* bullet = new NimbleBullet(NimbleBulletTexture, nimble_list_object->xpos, nimble_list_object->ypos);
			nimble_bullet_list.insert(nimble_bullet_list.begin(), bullet);
		}


	}

	if (nSpeedCount % 200 == 0) {
		if (missile_limit < 10) {
			missile_limit++;
		}
	}

	if (nSpeedCount % 30 == 0) {
		// animate sprites
		Middleware::animateOnce(nimble_bullet_list);
		Middleware::animateOnce(ranger_bullet_list);
		Middleware::animateOnce(user_bullet_list);
		Middleware::animateRepeat(user_missile_list);
	}

	// Move and Update
	Middleware::moveAndUpdate(ranger_list, nSpeedCount);
	Middleware::moveAndUpdate(explosion_list, nSpeedCount);
	Middleware::moveAndUpdate(nimble_list, nSpeedCount);
	Middleware::moveAndUpdate(ranger_bullet_list, nSpeedCount);
	Middleware::moveAndUpdate(nimble_bullet_list, nSpeedCount);
	Middleware::moveAndUpdate(user_bullet_list, nSpeedCount);
	Middleware::moveAndUpdate(user_missile_list, nSpeedCount);

	//Collision Detection
	for (int b = 0; b < user_bullet_list.size(); b++)
	{

		GameObject* userBulletObject = user_bullet_list.at(b);
		for (int n = 0; n < nimble_list.size(); n++)
		{
			GameObject* nimbleObject = nimble_list.at(n);
			if (nimbleObject->xpos - userBulletObject->xpos <= 80 && abs(nimbleObject->ypos - userBulletObject->ypos) <= 30) {
				nimbleObject->Dodge();
			}
			if (nimbleObject->xpos - userBulletObject->xpos <= 64 && abs(nimbleObject->ypos - userBulletObject->ypos) <= 30) {
				Middleware::createExplosion(nimbleObject, ExplosionTexture, explosion_list);
				nimbleObject->alive = false;
				userBulletObject->alive = false;
				score += 100;
			}
		}

	}

	for (int b = 0; b < user_bullet_list.size(); b++)
	{
		GameObject* userBulletObject = user_bullet_list.at(b);
		for (int r = 0; r < ranger_list.size(); r++)
		{
			GameObject* rangerObject = ranger_list.at(r);
			if (rangerObject->xpos - userBulletObject->xpos <= 64 && abs(rangerObject->ypos - userBulletObject->ypos) <= 30) {
				rangerObject->count_lives--;
				if (rangerObject->count_lives == 0) {
					Middleware::createExplosion(rangerObject, ExplosionTexture, explosion_list);
					rangerObject->alive = false;
					score += 300;
				}
				userBulletObject->alive = false;

			}
		}
	}

	for (int b = 0; b < user_missile_list.size(); b++)
	{
		GameObject* userMissileObject = user_missile_list.at(b);
		for (int n = 0; n < nimble_list.size(); n++)
		{
			GameObject* nimbleObject = nimble_list.at(n);
			if (nimbleObject->xpos - userMissileObject->xpos <= 64 && abs(nimbleObject->ypos - userMissileObject->ypos) <= 30) {
				Middleware::createExplosion(nimbleObject, ExplosionTexture, explosion_list);
				nimbleObject->alive = false;
				userMissileObject->alive = false;
				score += 100;
			}
		}
	}

	for (int b = 0; b < user_missile_list.size(); b++)
	{
		GameObject* userMissileObject = user_missile_list.at(b);
		for (int r = 0; r < ranger_list.size(); r++)
		{
			GameObject* rangerObject = ranger_list.at(r);
			if (rangerObject->xpos - userMissileObject->xpos <= 64 && abs(rangerObject->ypos - userMissileObject->ypos) <= 30) {
				rangerObject->count_lives--;
				if (rangerObject->count_lives == 0) {
					Middleware::createExplosion(rangerObject, ExplosionTexture, explosion_list);
					rangerObject->alive = false;
					score += 300;
				}
				userMissileObject->alive = false;

			}
		}
	}

	for (int b = 0; b < ranger_bullet_list.size(); b++)
	{
		GameObject* rangerBulletObject = ranger_bullet_list.at(b);
		if (abs(player->xpos - rangerBulletObject->xpos) <= 64 && abs(player->ypos - rangerBulletObject->ypos) <= 64) {
			Middleware::createExplosion(player, ExplosionTexture, explosion_list);
			rangerBulletObject->alive = false;
			player->alive = false;
			isRunning = false;
		}
	}

	for (int b = 0; b < nimble_bullet_list.size(); b++)
	{
		GameObject* nimbleBulletObject = nimble_bullet_list.at(b);
		if (abs(player->xpos - nimbleBulletObject->xpos) <= 64 && abs(player->ypos - nimbleBulletObject->ypos) <= 64) {
			Middleware::createExplosion(player, ExplosionTexture, explosion_list);
			nimbleBulletObject->alive = false;
			player->alive = false;
			isRunning = false;

		}
	}

	//Cleaning List
	Middleware::clean(user_bullet_list);
	Middleware::clean(nimble_bullet_list);
	Middleware::clean(ranger_bullet_list);
	Middleware::clean(nimble_list);
	Middleware::clean(ranger_list);
	Middleware::clean(user_missile_list);
	Middleware::clean(explosion_list);

}

void Game::update() {

	if (player->alive == true) {
		player->Update();
	}

}

void Game::clean() {
	score = 0;
	missile_limit = 10;
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyTexture(Missiles_Message);
	SDL_DestroyTexture(Score_Message);
	SDL_DestroyTexture(PlayerTexture);
	SDL_DestroyTexture(NimbleTexture);
	SDL_DestroyTexture(RangerTexture);
	SDL_DestroyTexture(SmokeTexture);
	SDL_DestroyTexture(ExplosionTexture);
	SDL_DestroyTexture(UserBulletTexture);
	SDL_DestroyTexture(UserMissileTexture);
	SDL_DestroyTexture(RangerBulletTexture);
	SDL_DestroyTexture(NimbleBulletTexture);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool Game::running() {
	return isRunning;
}

