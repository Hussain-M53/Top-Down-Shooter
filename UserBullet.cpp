#include "UserBullet.h"

UserBullet::UserBullet(SDL_Texture* texture,int x, int y) :GameObject(texture, x, y) {

}

void UserBullet::Move() {
	if (xpos <=864)
		this->xpos += 3;
	else
		alive = false;
}