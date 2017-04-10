#include "StateManager.h"

void StateManager::addState(State* s)
{
    if(!_states.empty())
    {
        _states.pop_back();
    }
    _states.push_back(s);
}

void StateManager::clean()
{
    while(!_states.empty())
    {
        _states.pop_back();
    }
}

void StateManager::update()
{
    _states.back()->update();
}

void StateManager::handleInput(SDL_Event &e)
{
    _states.back()->handleInput(e);
}

void StateManager::render(SDL_Renderer *renderer, TextureManager &manager)
{
    _states.back()->render(renderer, manager);
}