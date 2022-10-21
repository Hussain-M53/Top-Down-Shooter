#include "SDL.h" 
#include <stdio.h>
#include <vector>
#include "SDL_ttf.h"

#pragma once

using namespace std;

class Game {
	bool isRunning;
	SDL_Window* window;
public:
	Game();
	~Game();
	void initialize(const char* title, int x, int y, int width, int height, bool fullscrean);
	void updateScore(TTF_Font* SpaceFont, SDL_Rect& Missile_rect,SDL_Rect& Score_rect);
	void handleEvents();
	void render(TTF_Font* SpaceFont, SDL_Rect& Missile_rect, SDL_Rect& Score_rect);
	void update();
	void loadTextures();
	void handleListChanges();
	void clean();
	bool running();
	static SDL_Renderer* renderer;
};