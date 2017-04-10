#pragma once
#ifndef _MOTOR_H_
#define _MOTOR_H_

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

enum MotorType
{
    MOTOR_BASIC,
    MOTOR_ADVANCED,
    MOTOR_EXPERT
};

class Motor : public Machine
{
    // Public Main components
public:
    Motor(int x, int y);
    Motor(int x, int y, MotorType type);
    ~Motor();
    
    void update();
    void render(SDL_Renderer *renderer, TextureManager &manager, Camera &camera);
    void handleInput(SDL_Event &e, Camera &cam);
    
    // Public members
public:
    //int getEnergyUsage() const;
    //int getFuelUsage() const;
    
    int getCylCount() const;
    int getMaxCylCount() const;
    
    void increaseCylCount(int inc);
    void decreaseCylCount(int dec);
    
    // Private members
private:
    void calculateNewFuelUsage(int cylinderCount);
    
    // private variables
private:
    MotorType _type;
    int _maxCyl; // This is the total cylinders that can hook up to the system
    int _totalCyl; // This is the total cylinders connected tot the system
    
};

#endif