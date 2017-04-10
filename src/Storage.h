#pragma once
#ifndef _STORAGE_H_
#define _STORAGE_H_

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

#include <iostream>
#include "Machine.h"
#include "TextureManager.h"
#include "Camera.h"

class Storage : public Machine
{
public:
    Storage(int x, int y);
    ~Storage();
    
    void update();
    void render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera);
    void handleInput(SDL_Event &e, Camera &cam);
    
private:
    int _frameRate;
    int _totalFrame;
    int _frame;
    long _oldTime;
};

#endif