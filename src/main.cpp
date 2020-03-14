#include "game.h"
using namespace std;

int main(int argc, char* argv[]) {
    SDL_Window* gWindow = NULL;
    SDL_Renderer* gRenderer = NULL;

    if(initialize(gWindow, gRenderer) == false) {
		cout << "Failed to initialize!" << endl;
	}
	else {
	    //Objects declaration
        Texture backGround;
        Text messages;
        bird BIRD;
        LowerPipe L1, L2, L3;
        UpperPipe U1, U2, U3;
        Audio score_sound, flap_sound, hit_sound;
        //Load objects' properties
        load_objects(gRenderer, backGround, messages, BIRD, L1, L2, L3, U1, U2, U3, score_sound, flap_sound, hit_sound);
        //Enter game loop
        while (play(gWindow, gRenderer, backGround, messages, BIRD, L1, L2, L3, U1, U2, U3, score_sound, flap_sound, hit_sound)) {}
	}

	close(gWindow, gRenderer);
	return 0;
}
