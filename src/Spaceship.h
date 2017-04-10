#pragma once

#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Tile.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "Grid.h"
#include "Cylinder.h"
#include "EnergyCell.h"
#include "Machine.h"
#include "Motor.h"
#include "Storage.h"
#include "Unit.h"
#include "Gui.h"
#include "EnemyUnit.h"
#include "Inventory.h"

class Spaceship
{
public:
	Spaceship(AudioManager *_aManager);
    Spaceship(AudioManager *_aManager, const std::string &file, const std::string &machineFile);
    
    void handleInput(SDL_Event &e, Camera &cam);
    void update();
    void render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera);
    
    void openTile(int x, int y, int layer);
    
private:
    void createDefault();
    void constructFromSave();
    
	std::vector<std::vector<Tile>> _tiles;
    std::vector<std::shared_ptr<Machine>> _machines;
    std::vector<std::shared_ptr<Entity>> _entities;
    
    std::vector<std::string> _save; // only called on the save and load function
    std::vector<std::string> _machineSave;
    
private:
    int _filledStorage;
    int _maxStorage;
    
    int _filledEnergy;
    int _maxEnergy;
    
    int _filledShield;
    int _maxShield;
    
    int _minWorkers;
    int _maxWorkers;
    
private:
    Gui _gui;
    AudioManager *_aManager;

};

#endif