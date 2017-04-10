#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <vector>
#include <memory>
#include "TextureManager.h"
#include "Camera.h"

class Entity
{
public:
    Entity(int x, int y);
    Entity(Vector2 pos);
    ~Entity();
    
    float getX();
    float getY();
    
public:
    virtual void update(std::vector<std::shared_ptr<Entity>> entitys) = 0;
    virtual void render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera) = 0;
    virtual void handleInput(SDL_Event &e, Camera &cam) = 0;
    
protected:
    float _x;
    float _y;
    float _minHp;
    float _maxHp;
};

#endif