#include "Button.h"

Button::Button(const std::string &labelText, int x, int y, int w, int h, int type)
    : _x(x)
    , _y(y)
    , _w(w)
    , _h(h)
    , _type(0)
    , _buttonType(type)
    , _icon(-1)
    , _label(labelText)
{
    _isClicked = false;
}

Button::Button(const int icon, int x, int y, int w, int h, int type)
    : _x(x)
    , _y(y)
    , _w(w)
    , _h(h)
    , _type(0)
    , _buttonType(type)
    , _icon(icon)
    , _label(" ")
{
    _isClicked = false;
}

void Button::update()
{
}

void Button::render(SDL_Renderer *renderer, TextureManager &manager)
{
    if(_buttonType == 0)
    {
        manager.renderTextureFrame("ButtonNorm", Vector2(_x, _y), Vector2(_w, _h), Vector2(0, _type), renderer);
    }
    else if(_buttonType == 1)
    {
        manager.renderTextureFrame("Button", Vector2(_x, _y), Vector2(_w, _h), Vector2(0, _type), renderer);
    }
    else if(_buttonType == 2)
    {
        manager.renderTextureFrame("ButtonMenu", Vector2(_x, _y), Vector2(_w, _h), Vector2(0, _type), renderer);
    }
    
    if(_icon != -1)
    {
        manager.renderTextureFrame("Icons", Vector2(_x + 16, _y + 16), Vector2(32, 32), Vector2(_icon, 0), renderer);
    }
    else
    {
        SDL_Color col;
        col.r = col.g = col.b = 255;
        col.a = 255;
        
        manager.renderText("ButtonText", _label, Vector2(_w/2 + _x, _h/2 + _y), 1, 8, renderer, col);
    }
}

void Button::handleInput(SDL_Event &e, AudioManager *audioManager)
{
    if(e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
    {
        int x,y;
        SDL_GetMouseState(&x, &y);
        if(x > _x && x < _x + _w && y > _y && y < _y + _h)
        {
            // mouse is inside
            _type = 1;
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                _type = 2;
                audioManager->playSound("ButtonPress");
                _isClicked = true;
            }
            else
            {
                _isClicked = false;
            }
        }
        else
        {
            _isClicked = false;
            _type = 0;
        }
    }
}

void Button::setClicked(bool click)
{
    _isClicked = click;
}

bool Button::isClicked()
{
    return _isClicked;
}

void Button::setX(int value)
{
    _x = value;
}

void Button::setY(int value)
{
    _y = value;
}

int Button::getX()
{
    return _x;
}

int Button::getY()
{
    return _y;
}