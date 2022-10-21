#include "UserPlane.h"

UserPlane::UserPlane(SDL_Texture* texture,int x, int y) :GameObject (texture, x ,y) {
	tx = 0;
	ty = 0;
}

void UserPlane::Translate(int x, int y) {
	tx = x;
	ty = y;
}

void UserPlane::Move() {
	xpos += tx;
	//If the object went too far to the left or right
	if ((xpos < 0) || (xpos + 64 > 800))
	{
		//Move back
		xpos -= tx;
	}

	//Move the object up or down
	ypos += ty;

	//If the object went too far up or down
	if ((ypos < 40) || (ypos + 64 > 640))
	{
		//Move back
		ypos -= ty;
	}
	tx *= friction;
	ty *= friction;
}