#include "Ranger.h"

Ranger::Ranger(SDL_Texture* texture,int x, int y) : GameObject(texture, x, y) {
	this->count_lives = 3;

}

void Ranger::Move() {

	if (xpos >= -64)
		this->xpos --;
	else
		alive = false;
}

void Ranger::Dodge() {

	int random = rand() % 2;
	if (random == 0) {
		if (this->ypos >= 0) {
			this->ypos -= 10;
		}
	}
	else {
		if (this->ypos <= 600)
			this->ypos += 10;
	}


}