#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

//Screen size
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
//Objects' size
#define PIPE_WIDTH 100
#define PIPE_HEIGHT 600
#define BIRD_W 50
#define BIRD_H 35
//Distances and Positions
#define PIPE_HORIZONTAL_DIST 300
#define PIPE_VERTICAL_DIST 160
#define PIPE_RESPAWN_POS -100
#define GROUND 565
#define Bird_POSx 200
#define Bird_POSy 250
//Other parameter
#define FPS 40 //frames per second
#define SPEED 4 //pixels/frame
#define FLAP_VELOCITY -12 //pixels/frame
#define g 1 //gravitational acceleration: pixels/frame
#define a 9 //angle acceleration: degrees/frame

/*
    CLASSES', FUNCTIONS' DECLARATIONs
*/
struct Texture {
    SDL_Texture* texture;
    SDL_Rect sprite;
    int x;
    int y;
    int W;
    int H;

    Texture();
    void free();
    bool loadFromFile(const string& img_path, SDL_Renderer* gRenderer);
    void update_sprite();
};

class bird : public Texture {
    int Vy;
    int angle;

    public:
    SDL_Rect clip[3];
    bird();
    bool is_OnTheGround();
    int getAngle();
    void flap();
    void setClips();
    void update_pos();
};

class LowerPipe : public Texture {
    int Vy;

    public:
    LowerPipe();
    void update_pos(const LowerPipe& previousPipe, const int &score);
    void setVy(int vy);
};

class UpperPipe : public Texture {
    public:
    UpperPipe();
    void update_pos(const LowerPipe& Lower);
};

struct Text {
    SDL_Texture* texture;
    SDL_Rect clipBoard;
    SDL_Color textColor;
    int x;
    int y;

    Text();
    void free();
    void load( const string& text, const int size, SDL_Renderer* gRenderer );
};

class Audio {
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    SDL_AudioDeviceID deviceId;

    public:
    Audio();
    //Deallocator
    //~Audio(); //Deprecated for being error prone
    //load WAV file
    void load(const char* filename);
    //play audio
    void play();
};

// OPERATIONS
    //Initialize window
    bool initialize(SDL_Window* &gWindow, SDL_Renderer* &gRenderer);

    //Play the game once (from the start until the bird bumps a pipe and falls)
    bool play(SDL_Window* &gWindow, SDL_Renderer* &gRenderer, Texture &backGround, Text &messages,
         bird &BIRD, LowerPipe &L1, LowerPipe &L2, LowerPipe &L3, UpperPipe &U1, UpperPipe &U2, UpperPipe &U3,
         Audio &score_sound, Audio &flap_sound, Audio &hit_sound);

    //Load objects' properties
    void load_objects(SDL_Renderer* gRenderer, Texture &backGround, Text &messages,
         bird &BIRD, LowerPipe &L1, LowerPipe &L2, LowerPipe &L3, UpperPipe &U1, UpperPipe &U2, UpperPipe &U3,
         Audio &score_sound, Audio &flap_sound, Audio &hit_sound);

    //Set objects' initial state
    void set_objects(SDL_Renderer* gRenderer, Texture &backGround, Text &messages,
         bird &BIRD, LowerPipe &L1, LowerPipe &L2, LowerPipe &L3, UpperPipe &U1, UpperPipe &U2, UpperPipe &U3,
         Audio &score_sound, Audio &flap_sound, Audio &hit_sound);

    //Display final score & check if player want to play again
    bool end_game(SDL_Renderer* gRenderer, SDL_Event &e, int &score, Text &messages);

    //Frees media and shuts down SDL
    void close(SDL_Window* &gWindow, SDL_Renderer* &gRenderer);

