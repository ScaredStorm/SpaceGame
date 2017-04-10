#pragma once
#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <stdio.h>
#include "TextureManager.h"
#include "StateManager.h"
#include "AudioManager.h"
#include "State.h"
#include "Spaceship.h"
#include "Game.h"
#include "Camera.h"

class GameState : public State
{
public:
    GameState(StateManager *stateManager, AudioManager *audioManager);
    
    void update();
    void render(SDL_Renderer *renderer, TextureManager &manager);
    void handleInput(SDL_Event &e);
    
private:
    StateManager *_sManager;
    AudioManager *_aManager;
    
    Spaceship _ship;
    Camera _cam;
    
private:
    int _mX, _mY;
    int _sX, _sY;
    bool _dragging;
    
};

#endif
