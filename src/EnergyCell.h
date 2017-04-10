#pragma once
#ifndef _ENERGYCELL_H_
#define _ENERGYCELL_H_

#ifdef _WIN32
	#include <SDL.h>
	#include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include "Machine.h"
#include "TextureManager.h"
#include "Camera.h"
#include "Vector2.h"

class EnergyCell : public Machine
{
public:
	EnergyCell(int x, int y);
	~EnergyCell();

	void update();
	void render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera);
	void handleInput(SDL_Event &e, Camera &cam);

private:
	// ?
};

#endif