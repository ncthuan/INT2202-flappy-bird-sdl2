#include "game.h"
using namespace std;

// Class LowerPipe
LowerPipe::LowerPipe()
{
    texture = NULL;
    W = PIPE_WIDTH;
    H = PIPE_HEIGHT;
    Vy = 0;
    update_sprite();
}

void LowerPipe::update_pos(const LowerPipe& previousPipe, const int &score)
{
    //update coordinates
    x += -SPEED;
    y += Vy;
    //check if pipe reach respawn point
    if (x <= PIPE_RESPAWN_POS) {
        //respawn pipe
        x = SCREEN_WIDTH;
        //randomly generate pipe's height
        y = previousPipe.y + (rand()%800 - 400);
        if (y <= PIPE_VERTICAL_DIST + 50) y = PIPE_VERTICAL_DIST + 50 + (PIPE_VERTICAL_DIST + 50 - y);
        if (y >= 550) y = 550 - (y - 550);
        //randomly generate pipe's vertical velocity
        int move_rate = 30 + score*2; //(%)
        if (Vy != 0) Vy = 0;
        if (rand()%100 < move_rate) Vy = (y < 400 ? 1 : -1);
    }
    //sync
    update_sprite();
}

void LowerPipe::setVy(int vy) { Vy = vy; }

// Class UpperPipe
UpperPipe::UpperPipe()
{
    texture = NULL;
    W = PIPE_WIDTH;
    H = PIPE_HEIGHT;
    update_sprite();
}

void UpperPipe::update_pos(const LowerPipe& Lower)
{
    //update coordinates according to lowerPipe
    x = Lower.x;
    y = Lower.y - PIPE_VERTICAL_DIST - 600;
    //check if pipe reach respawn point
    if (x <= PIPE_RESPAWN_POS) {
        //respawn pipe
        x = SCREEN_WIDTH;
    }
    //sync
    update_sprite();
}
