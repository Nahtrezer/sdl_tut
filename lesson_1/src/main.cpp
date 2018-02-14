#include <iostream>
#include "SDL.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** argv) {

    SDL_Window* gWindow = NULL;
    SDL_Surface* gSurface = NULL;

        if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Error SDL_Init: " << SDL_GetError() << std::endl;
    } else {
        gWindow = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        gSurface = SDL_GetWindowSurface(gWindow);

        SDL_FillRect(gSurface, NULL, SDL_MapRGB(gSurface->format, 135, 206, 250));
        SDL_UpdateWindowSurface(gWindow);
        SDL_Delay(2000);
    }
}