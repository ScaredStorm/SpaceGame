#pragma once
#ifndef _TILE_H_
#define _TILE_H_

#ifdef _WIN32
	#include <SDL.h>
#else
	#include <SDL2/SDL.h>
#endif

#include "Vector2.h"
#include "TextureManager.h"
#include "Camera.h"

enum TileType
{
    TYPE_EMPTY,
    TYPE_NORMAL
};

class Tile
{
public:
	Tile(Vector2 position, TileType type);
	Tile(int x, int y, TileType type);
	Tile(int x, int y, SDL_Color color, TileType type);
	~Tile();

	void setColor(SDL_Color color);
	void setColor(Uint8 r, Uint8 g, Uint8 b);
    void setType(TileType type);
	void render(TextureManager &manager, SDL_Renderer *renderer, Camera &camera);
    
private:
	SDL_Color _col;
	Vector2 _position;
    TileType _type;

};

#endif