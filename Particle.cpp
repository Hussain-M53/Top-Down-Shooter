#include "SmokeParticle.h";
#include "Smoke.h";
#include <iostream>
#include <SDL.h>
#include <stdio.h>

using namespace std;



Particle::Particle(int x, int y)
{

    //Set offsets
    mPosX = x - 5 + (rand() % 25);
    mPosY = y - 5 + (rand() % 25);


    //Initialize animation
    mFrame = rand() % 5;

}

void Particle::render()
{
    //Animate
    mFrame++;
}

bool Particle::isDead()
{
    return mFrame > 10;
}