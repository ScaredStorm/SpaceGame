#pragma once
#ifndef _MENUSTATE_H_
#define _MENUSTATE_H_

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
#include "Button.h"
#include "Vector2.h"
#include "GameState.h"

class MenuState : public State
{
public:
    MenuState(StateManager *stateManger, AudioManager *audioManager);
    
    void update();
    void render(SDL_Renderer *renderer, TextureManager &manager);
    void handleInput(SDL_Event &e);
    
private:
    StateManager *_sManager;
    AudioManager *_aManager;
    
private:
    Button _mbStart;
    Button _mbInfo;
    Button _mbQuit;
};

#endif
