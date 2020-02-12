#include "game.h"
using namespace std;

Audio::Audio() {}

//Deprecated for being error prone
//Audio::~Audio()
//{
//    SDL_CloseAudioDevice(deviceId);
//    SDL_FreeWAV(wavBuffer);
//}

void Audio::load(const char* filename)
{
    if ( !SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength) ) cout << "Can not load wave file: " << filename << endl;
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
}

void Audio::play()
{
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
}
