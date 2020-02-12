#include "game.h"
using namespace std;

int main(int argc, char* argv[])
{
    SDL_Window* gWindow = NULL;
    SDL_Renderer* gRenderer = NULL;

    if( !initialize(gWindow, gRenderer) )
	{
		cout << "Failed to initialize!" << endl;
	}
	else
	{
		while ( play(gWindow, gRenderer) ) {}
	}

	close(gWindow, gRenderer);
	return 0;
}
