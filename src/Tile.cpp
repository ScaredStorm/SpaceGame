#include "Tile.h"

Tile::Tile(Vector2 position, TileType type)
	: _position(position.x, position.y)
{
	_col.r = 255;
	_col.g = 255;
	_col.b = 255;
	_col.a = 255;
    
    _type = type;
}

Tile::Tile(int x, int y, TileType type)
	: _position(Vector2(x, y))
{
	_col.r = 255;
	_col.g = 255;
	_col.b = 255;
	_col.a = 255;
    
    _type = type;
}

Tile::Tile(int x, int y, SDL_Color color, TileType type)
	: _position(Vector2(x, y))
{
	_col = color;
    
    _type = type;
}

Tile::~Tile()
{
}

void Tile::setColor(SDL_Color color)
{
	_col = color;
}
void Tile::setColor(Uint8 r, Uint8 g, Uint8 b)
{
	_col.r = r;
	_col.g = g;
	_col.b = b;
	_col.a = 255;
}

void Tile::setType(TileType type)
{
    _type = type;
}

void Tile::render(TextureManager &manager, SDL_Renderer *renderer, Camera &camera)
{
    Vector2 calculatedPos = Vector2(_position.x - camera.getX(), _position.y - camera.getY());
    if(_type == TYPE_NORMAL)
    {
        manager.renderTexture("Tile", calculatedPos, Vector2(64, 32), renderer);
        //manager.renderTextureColor("Tile", calculatedPos, Vector2(64, 32), renderer, {255,0,255,255});
    }
}









