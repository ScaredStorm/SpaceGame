#pragma once
#ifndef _SPLASHSTATE_H_
#define _SPLASHSTATE_H_

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
#include "MenuState.h"

class SplashState : public State
{
public:
    SplashState(StateManager *stateManger, AudioManager *audioManager);
    
    void update();
    void render(SDL_Renderer *renderer, TextureManager &manager);
    void handleInput(SDL_Event &e);
    
private:
    StateManager *_sManager;
    AudioManager *_aManager;
    
private:
    int _timeCountDown;
    Uint32 _oldTime;
};

#endif
