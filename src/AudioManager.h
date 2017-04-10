#pragma once
#ifndef _AUDIOMANAGER_H_
#define _AUDIOMANAGER_H_

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_mixer.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2_mixer/SDL_mixer.h>
#endif

#include <stdio.h>
#include <map>
#include <string>

class AudioManager
{
public:
	~AudioManager();

    void addSound(const std::string &key, const std::string &path);
    void removeSound(const std::string &key);
    
    void addMusic(const std::string &key, const std::string &path);
    void removeMusic(const std::string &key);
    
    void playMusic(const std::string &key, int loop);
    void playSound(const std::string &key);
    
    void stopMusic(const std::string &key);
private:
    std::map<std::string, Mix_Chunk*> _soundEffects;
    std::map<std::string, Mix_Music*> _music;
};

#endif
