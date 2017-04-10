#pragma once
#ifndef _DISPLAYCONTAINER_H_
#define _DISPLAYCONTAINER_H_

#ifdef _WIN32
	#include <SDL.h>
	#include <SDL_image.h>
#else
	#include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <vector>
#include <stdio.h>
#include "TextureManager.h"
#include "Camera.h"
#include "Vector2.h"

class DisplayContainer
{

public:
	DisplayContainer(const int size, const int rX, const int rY, const int rowCount, const int columnCount);
	~DisplayContainer();

	void setRenderX(int x);
	void setRenderY(int y);

	void render(SDL_Renderer *renderer, TextureManager &manager, Camera &cam);
	void update();
	void handleInput(SDL_Event &e, Camera &cam);

private:
	std::vector<int> _items;

private:
	int _x, _y;
	int _size;
	int _rowCount;
	int _columnCount;

};

#endif