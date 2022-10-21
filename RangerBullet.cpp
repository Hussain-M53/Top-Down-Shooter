#include "RangerBullet.h"
#include <math.h>
#define PI 3.14159265

RangerBullet::RangerBullet(SDL_Texture* texture,int x, int y, int playerX, int playerY) :GameObject(texture, x, y) {
	movX = playerX - xpos;
	movY = playerY - ypos;
	angle = atan2(movY, movX);
	angleDegree = (angle * 180 / PI) - 180;
}

void RangerBullet::Move() {
	if (xpos >= -64 && ypos >= -64 && ypos <= 704) {
		this->xpos += 2 * cos(angle);
		this->ypos += 2 * sin(angle);
	}
	else {
		alive = false;
	}
}

void RangerBullet::Render() {

	SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &desRect, angleDegree, NULL, SDL_FLIP_NONE);
}
