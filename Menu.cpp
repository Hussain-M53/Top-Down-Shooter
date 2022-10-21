#include <SDL.h>
#include <SDL_image.h>
#include "CreateTexture.h"
#include <cstdlib>
#include <iostream>
#include "Menu.h"
#include <SDL_ttf.h>
#include <stdio.h>

using namespace std;


Menu::Menu() {}
Menu::~Menu() {}

SDL_Rect rect;
SDL_Surface* surfaceMessage3;
SDL_Texture* Message3;

int Menu::initialize(const char* title, int x, int y, int width, int height, bool fullscrean) {

	SDL_Window* window = NULL;
	SDL_Texture* currImage = NULL;
	SDL_Renderer* render = NULL;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, 0);
	if (render) {
		SDL_SetRenderDrawColor(render, 76, 103, 147, 255);
	}
	SDL_Surface* tempSurface = IMG_Load("Images/PlayGame.png");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render, tempSurface);
	SDL_Rect srcR, desR;
	srcR.w = 530;
	srcR.h = 135;
	desR.w = 530;
	desR.h = 135;
	desR.x = (width - 530) / 2;
	desR.y = (height - 135) / 2;
	SDL_FreeSurface(tempSurface);
	currImage = texture;

	TTF_Init();
	TTF_Font* SpaceFont = TTF_OpenFont("Font/SpaceMission-rgyw9.otf", 50);
	SDL_Color Color = { 255, 255, 255 ,255 };

	surfaceMessage3 = TTF_RenderText_Solid(SpaceFont, "Top Down Shooter", Color);
	Message3 = SDL_CreateTextureFromSurface(render, surfaceMessage3);

	rect.x = 175;
	rect.y =100;
	rect.w = 100;
	rect.h = 100;

	SDL_QueryTexture(Message3, NULL, NULL, &rect.w, &rect.h);

	bool isMenu = true;
	SDL_Event event;

	while (isMenu) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) isMenu = false;
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (SDL_BUTTON_LEFT == event.button.button) {
					if (x >= 135 && x <= 395 && y >= 255 && y <= 387) {
						SDL_DestroyTexture(texture);
						SDL_DestroyRenderer(render);
						SDL_DestroyWindow(window);
						TTF_Quit();
						SDL_Quit();
						return 1;
					}
					if (x >= 409 && x <= 661 && y >= 260 && y <= 383) {
						isMenu = false;
						SDL_DestroyTexture(texture);
						SDL_DestroyRenderer(render);
						SDL_DestroyWindow(window);
						SDL_Quit();
						return 0;
					}
				}

			}
		}

		SDL_RenderClear(render);
		SDL_RenderCopy(render, Message3, NULL, &rect);
		SDL_RenderCopy(render, currImage, NULL, &desR);
		SDL_RenderPresent(render);
	}




	return 0;
}

