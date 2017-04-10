#pragma once

#ifndef _CAMERA_H_
#define _CAMERA_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include "Vector2.h"

class Camera
{
public:
    Camera(int x, int y, int width, int height);
    void setX(int x);
    void setY(int y);
    void setPosition(Vector2 position);
    
    int getX();
    int getY();
    
    Vector2 getPosition();
    
private:
    int _x;
    int _y;
    int _width;
    int _height;
};

#endif