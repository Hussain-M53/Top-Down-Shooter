#include "NimbleBullet.h"
#include <math.h>
#define PI 3.14159265

NimbleBullet::NimbleBullet(SDL_Texture* texture, int x, int y) :GameObject(texture, x, y) {

}

void NimbleBullet::Move() {
	if (xpos >= -64)
		this->xpos -= 3;
	else
		alive = false;
}
