#include "GameState.h"

GameState::GameState(StateManager *stateManager, AudioManager *audioManager)
: _cam(0, 0, 1280, 720)
, _ship(audioManager, Game::getResourcePath("/Saves/save2"), Game::getResourcePath("/Saves/save2-machines"))
{
    _sManager = stateManager;
    _aManager = audioManager;
    _dragging = false;

	_aManager->playMusic("BackgroundMs", -1);
}

void GameState::update()
{
    if(_dragging)
    {
        Vector2 newPos = Vector2(_cam.getX() + (_sX - _mX), _cam.getY() + (_sY - _mY));
        _sX = _mX;
        _sY = _mY;
        _cam.setPosition(newPos);
    }
    
    // ship update
    _ship.update();
}

void GameState::render(SDL_Renderer *renderer, TextureManager &manager)
{
    _ship.render(renderer, manager, _cam);
}

void GameState::handleInput(SDL_Event &e)
{
    if(e.type == SDL_KEYDOWN)
    {
        /*if(e.key.keysym.sym == SDLK_SPACE)
        {
            _sManager->addState(new MenuState(_sManager));
        }*/
    }
    
    if(e.type == SDL_MOUSEMOTION)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            if(!_dragging)
            {
                _sX = e.button.x;
                _sY = e.button.y;
                _dragging = true;
            }
            _mX = e.button.x;
            _mY = e.button.y;
            //std::printf("mX:%d, mY:%d, dsx:%d, dsy:%d\n", mX, mY, dragStartX, dragStartY);
        }
    }
    else
    {
        _dragging = false;
    }
    
    /* SHIP INPUT */
    _ship.handleInput(e, _cam);
}