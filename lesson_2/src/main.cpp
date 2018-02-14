#include <iostream>
#include "SDL.h"

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gImageSurface = NULL;

void logError(std::string message) {
    std::cout << message << SDL_GetError() << std::endl;
}

bool init() {
    bool successInit = true;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        logError("SDL failed initializing: ");
    } else {
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            logError("SDL_Window failed: ");
            successInit = false;
        } else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return successInit;
}

void close() {
    SDL_FreeSurface(gImageSurface);
    gImageSurface = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

bool loadMedia() {
    bool successLoad = true;
    gImageSurface = SDL_LoadBMP("../../resources/preview.bmp");
    if (gImageSurface == NULL) {
        logError("Image load failed");
        successLoad = false;
    }

    return successLoad;
}


int main(int argc, char** argv) {
    if(!init()) {
        logError("Failed startup");
    } else {
        if(!loadMedia()) {
            logError("Failed load media");
        } else {
            SDL_BlitSurface(gImageSurface, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
            SDL_Delay(3000);
        }
    }

    close();
    
    return 0;
}