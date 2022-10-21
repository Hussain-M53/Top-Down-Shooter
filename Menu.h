#include "SDL.h" 
#include <stdio.h>
#pragma once

using namespace std;

class Menu {
	bool isMenu;
	SDL_Window* window;
public:
	Menu();
	~Menu();
	int initialize(const char* title, int x, int y, int width, int height, bool fullscrean);
	SDL_Renderer* render;
};