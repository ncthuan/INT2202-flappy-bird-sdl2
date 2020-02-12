#include "game.h"
using namespace std;

Text::Text()
{
    texture = NULL;
    textColor = { 0xFF, 0xFF, 0xFF, 220 };
    x = 0;
    y = 0;
    clipBoard.x = 0;
    clipBoard.y = 0;
}

void Text::free()
{
    //Deallocates texture
    if( texture != NULL ) SDL_DestroyTexture( texture );
}

void Text::load(const string& text, const int size, SDL_Renderer* gRenderer)
{
    //Get rid of preexisting texture
	free();

    //Load font
	TTF_Font* font = TTF_OpenFont( "barcade.ttf", size );

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( font, text.c_str(), textColor );
	if( textSurface == NULL ) cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << endl;
	else
    {
		//Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( texture == NULL ) cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << endl;
		else
		{
			//Update clipBoard dimensions and coordinates to the middle of the screen
			clipBoard.w = textSurface->w;
			clipBoard.h = textSurface->h;
			clipBoard.x = (SCREEN_WIDTH - textSurface->w) / 2;
			clipBoard.y = 150;
		}
		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
    TTF_CloseFont( font );
}
