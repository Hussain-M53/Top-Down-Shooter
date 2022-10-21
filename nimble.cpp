#include "nimble.h"

nimble::nimble(SDL_Texture* texture, int x, int y) : GameObject(texture, x, y) {
}

void nimble::Move() {
	if (xpos >= -64)
		this->xpos --;
	else
		alive = false;
}

void nimble::Dodge() {

	int random = rand() % 2;
	if (random == 0) {
		if (this->ypos >= 0) {
			this->ypos -= 20;
		}
	}
	else {
			if (this->ypos <= 600) 
			this->ypos += 20;
	}


}
