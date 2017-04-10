#pragma once
#ifndef _ENEMYUNIT_H_
#define _ENEMYUNIT_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <stdio.h>
#include <memory>
#include "Entity.h"
#include "TextureManager.h"
#include "Camera.h"

class EnemyUnit : public Entity
{
public:
    EnemyUnit(int x, int y);
    ~EnemyUnit();
    
    void setPath(Vector2 position);
    
    void update(std::vector<std::shared_ptr<Entity>> entitys);
    void render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera);
    void handleInput(SDL_Event &e, Camera &cam);
    
private:
    int _frameRate;
    int _totalFrame;
    int _frame;
    long _oldTime;
    
    Vector2 destination;
private:
	void findClosest(std::vector<std::shared_ptr<Entity>> entitys);
    
};

#endif
