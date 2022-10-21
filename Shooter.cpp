#include <SDL.h>
#include <stdio.h>
#include "Game.h"
#include "Menu.h"
#include "GameObject.h"
#include <vector>
#include <iostream>
#include <stdlib.h> 
#include "Ranger.h"
#include "SDL_ttf.h"


using namespace std;

Game* game = nullptr;
Menu* menu = nullptr;
int value = -1;

int main(int argc, char* args[])
{
	while (true) {
	menu = new Menu();

		value = menu->initialize("Top Down Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

		if (value == 1) {
			const int FPS = 60;
			const int frame_delay = 1000 / FPS;
			Uint32 frame_start;
			int frame_time;

			game = new Game();
			game->initialize("Top Down Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
			TTF_Font* SpaceFont = TTF_OpenFont("Font/SpaceMission-rgyw9.otf", 24);
			SDL_Rect Missile_rect;
			Missile_rect.x = 570;
			Missile_rect.y = 10;
			Missile_rect.w = 100;
			Missile_rect.h = 100;
			SDL_Rect Score_rect;
			Score_rect.x = 30;
			Score_rect.y = 10;
			Score_rect.w = 100;
			Score_rect.h = 100;
			while (game->running()) {
				frame_start = SDL_GetTicks();
				game->handleEvents();
				game->handleListChanges();
				game->update();
				game->render(SpaceFont, Missile_rect, Score_rect);
				frame_time = SDL_GetTicks();

				if (frame_delay > frame_time) {
					SDL_Delay(frame_delay - frame_time);
				}
			}
			game->clean();
		}
		else
			break;
	}
	return 0;
}

