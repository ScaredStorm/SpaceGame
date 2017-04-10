#pragma once

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <stdio.h>
#include <vector>

#include "TextureManager.h"
#include "DisplayContainer.h"
#include "Camera.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void setItem(int id);
	void update();
	void render(SDL_Renderer *renderer, TextureManager &manager, Camera &cam);

private:
	std::vector<DisplayContainer*> _items;
};