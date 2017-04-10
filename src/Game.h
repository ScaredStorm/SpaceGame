#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>

#ifdef _WIN32
	#include <SDL.h>
	#include <SDL_image.h>
    #include <SDL_ttf.h>
    #include <SDL_mixer.h>
#else
	#include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
    #include <SDL2_ttf/SDL_ttf.h>
    #include <SDL2_mixer/SDL_mixer.h>
#endif

#include <stdlib.h>
#include <string>
#include <math.h>

#include "TextureManager.h"
#include "Tile.h"
#include "Grid.h"
#include "Spaceship.h"
#include "Camera.h"
#include "MenuState.h"
#include "GameState.h"
#include "SplashState.h"
#include "StateManager.h"
#include "AudioManager.h"

class Game
{
public:
	Game(const std::string &title, int width, int height);
	~Game();

	bool initGame();
    void initAssets();

	void run();
	void update();
	void render();
	void handleInput();
    
    static std::string getResourcePath(const std::string &path);

private:
	const int _WIDTH;
	const int _HEIGHT;
	const std::string _TITLE;

	SDL_Window *_window;
	SDL_Renderer *_renderer;
    TextureManager _texManager;
    StateManager _stateManager;
    AudioManager _audManager;
	
    bool _isRunning;

};

#endif