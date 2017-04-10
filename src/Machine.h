#pragma once
#ifndef _MACHINE_H_
#define _MACHINE_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include "Vector2.h"
#include "TextureManager.h"
#include "Camera.h"

typedef struct
{
	std::string name;
	int maxEnergyGeneration;
	int maxEnergyUsage;
	int maxFuelUsage;
	int maxEnergy;
	int maxFuel;
} MACHINE_INFO;

class Machine
{
public:
    Machine(int x, int y);
    Machine(Vector2 pos);
    ~Machine();
    
    int getX();
    int getY();
    
    virtual void update() = 0;
    virtual void render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera) = 0;
    virtual void handleInput(SDL_Event &e, Camera &cam) = 0;

	MACHINE_INFO getInfo();
    
protected:
    int _x;
    int _y;
    
	MACHINE_INFO info;
    
};

#endif