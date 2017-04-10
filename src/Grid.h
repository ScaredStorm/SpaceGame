#pragma once
#ifndef _GRID_H_
#define _GRID_H_

#ifdef _WIN32
	#include <SDL.h>
#else
	#include <SDL2/SDL.h>
#endif

const int tileSizeX = 32;
const int tileSizeY = 16;

class Grid
{
public:
	void render(SDL_Renderer *renderer);
    static int getPosX(int gridPos);
    static int getPosY(int gridPos);
    static int getMachinePosX(int gridPos);
    static int getMachinePosY(int gridPos);
};

#endif