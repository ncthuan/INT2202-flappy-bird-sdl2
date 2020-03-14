#include "game.h"
using namespace std;

Texture::Texture() {
    texture = NULL;
    x = 0;
    y = 0;
    W = 0;
    H = 0;
}

void Texture::free() {
    //Deallocates texture
    if (texture != NULL) {
        SDL_DestroyTexture(texture);
        W = 0;
        H = 0;
    }
}

bool Texture::loadFromFile(const string& img_path, SDL_Renderer* gRenderer) {
    //Get rid of preexisting texture
    free();

    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(img_path.c_str());
    if (loadedSurface == NULL)
        cout << "Unable to load image: " << SDL_GetError() << endl;
    else {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));

        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if (texture == NULL)
            cout << "Unable to create texture: " << SDL_GetError() << endl;
        else {
            //Get image dimensions
            W = loadedSurface->w;
            H = loadedSurface->h;
            update_sprite();
        }
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    //Return success
    return texture != NULL;
}

void Texture::update_sprite() {
    //update position of the sprite
    sprite.x = x;
    sprite.y = y;
    sprite.h = H;
    sprite.w = W;
}
