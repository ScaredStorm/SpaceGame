#pragma once
#ifndef _BUTTON_H_
#define _BUTTON_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <string>
#include <stdio.h>
#include "TextureManager.h"
#include "AudioManager.h"
#include "Camera.h"
#include "Vector2.h"

class Button
{
public:
    Button(const std::string &labelText, int x, int y, int w, int h, int type = 0);
    Button(const int icon, int x, int y, int w, int h, int type = 0);
    
    void update();
    void render(SDL_Renderer *renderer, TextureManager &manager);
    void handleInput(SDL_Event &e, AudioManager *audioManager);
    
    void setClicked(bool click);
    bool isClicked();
    
    void setX(int value);
    int getX();
    
    void setY(int value);
    int getY();
    
private:
    int _x;
    int _y;
    int _w;
    int _h;
    std::string _label;
    int _icon;
    
    int _type;
    bool _isClicked;
    int _buttonType;
    
};

#endif
