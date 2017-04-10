#pragma once
#ifndef _UNIT_H_
#define _UNIT_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <iostream>
#include <math.h>
#include <memory>
#include "Entity.h"
#include "TextureManager.h"
#include "Camera.h"
#include "Grid.h"
#include "DisplayContainer.h"

class Unit : public Entity
{
public:
    Unit(int x, int y);
    ~Unit();
    
    void setPath(Vector2 position);
    bool isSelected();
    
    void update(std::vector<std::shared_ptr<Entity>> entitys);
    void render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera);
    void handleInput(SDL_Event &e, Camera &cam);
    
private:
    int _frameRate;
    int _totalFrame;
    int _frame;
    long _oldTime;
    
    Vector2 destination;
    bool _selected;
	DisplayContainer _inv;
	bool _showInventory;
};

#endif
