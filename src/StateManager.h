#pragma once
#ifndef _STATEMANAGER_H_
#define _STATEMANAGER_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <iostream>
#include <stdio.h>
#include <vector>
#include "TextureManager.h"
#include "Camera.h"
#include "State.h"

class StateManager
{
public:
    void addState(State* s);
    void clean();
    
    void update();
    void handleInput(SDL_Event &e);
    void render(SDL_Renderer *renderer, TextureManager &manager);
private:
    std::vector<State*> _states;
};

#endif
