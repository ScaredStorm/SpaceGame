#pragma once
#ifndef _GUI_H_
#define _GUI_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <vector>
#include <memory>
#include "Vector2.h"
#include "TextureManager.h"
#include "StateManager.h"
#include "AudioManager.h"
#include "DisplayContainer.h"
#include "Machine.h"
#include "Button.h"

class Gui
{
public:
    Gui(AudioManager *audioManager);
    ~Gui();
    
    void update(std::vector<std::shared_ptr<Machine>> m);
    void render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera);
    void handleInput(SDL_Event &e);
private:
    std::vector<std::shared_ptr<Machine>> _machines;
private:
    Button _b;
    AudioManager *_aManager;
};

#endif
