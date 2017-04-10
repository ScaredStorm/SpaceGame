#include "AudioManager.h"

AudioManager::~AudioManager()
{
	//delete[] _music;
	//delete[] _soundEffects;
}

void AudioManager::addSound(const std::string &key, const std::string &path)
{
    Mix_Chunk *temp = Mix_LoadWAV(path.c_str());
    if(temp == nullptr)
    {
        std::printf("Sound Load Error: %s\n", Mix_GetError());
    }
    _soundEffects[key] = temp;
}

void AudioManager::removeSound(const std::string &key)
{
    if(_soundEffects.find(key) != _soundEffects.end())
    {
        Mix_FreeChunk(_soundEffects[key]);
        _soundEffects.erase(key);
    }
}

void AudioManager::addMusic(const std::string &key, const std::string &path)
{
    Mix_Music *temp = Mix_LoadMUS(path.c_str());
    if(temp == nullptr)
    {
        std::printf("Music Load Error: %s\n", Mix_GetError());
    }
    _music[key] = temp;
}

void AudioManager::removeMusic(const std::string &key)
{
    if(_music.find(key) != _music.end())
    {
        Mix_FreeMusic(_music[key]);
        _music.erase(key);
    }
}

void AudioManager::playMusic(const std::string &key, int loop)
{
    if(Mix_PlayMusic(_music[key], loop) != 0)
    {
        std::printf("Music Play error: %s\n", Mix_GetError());
        return;
    }
}

void AudioManager::playSound(const std::string &key)
{
    if(Mix_PlayChannel(-1, _soundEffects[key], 0) != 0)
    {
        std::printf("Effect Play error: %s\n", Mix_GetError());
        return;
    }
}

void AudioManager::stopMusic(const std::string &key)
{
    Mix_HaltMusic();
}