#pragma once
#ifndef _STATE_H_
#define _STATE_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <stdio.h>
#include "TextureManager.h"

class State
{
public:
    virtual void update() = 0;
    virtual void render(SDL_Renderer *renderer, TextureManager &manager) = 0;
    virtual void handleInput(SDL_Event &e) = 0;
};

#endif
