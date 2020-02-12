#include "game.h"
using namespace std;

bird::bird()
{
    //initialize bird
    texture = NULL;
    x = Bird_POSx;
    y = Bird_POSy;
    angle = 0;
    Vy = 0;
    update_sprite();
}

bool bird::is_OnTheGround()
{
    return ( y >= GROUND);
}

int bird::getAngle()
{
    return angle;
}

void bird::flap()
{
    Vy = FLAP_VELOCITY; // pixels/frame
    angle = -25;        //degree
}

void bird::setClips()
{
    //Set sprite clips
    clip[ 0 ].x =   0;
    clip[ 0 ].y =   0;
    clip[ 0 ].w =  78;
    clip[ 0 ].h =  56;

    clip[ 1 ].x =  78;
    clip[ 1 ].y =   0;
    clip[ 1 ].w =  78;
    clip[ 1 ].h =  56;

    clip[ 2 ].x = 156;
    clip[ 2 ].y =   0;
    clip[ 2 ].w =  78;
    clip[ 2 ].h =  56;
}

void bird::update_pos()
{
    //update y
    y += Vy;
    //set ground bound
    if ( is_OnTheGround() ) y = GROUND;
    //sync
    update_sprite();
    //change the bird's angle
    if (Vy > 7) angle += a;
    if ( angle >= 90 ) angle = 90;
    //apply gravity
    Vy += g;
}
