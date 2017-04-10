#pragma once
#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#ifdef _WIN32
	#include <SDL.h>
	#include <SDL_image.h>
    #include <SDL_ttf.h>
#else
	#include <SDL2/SDL.h>
	#include <SDL2_image/SDL_image.h>
    #include <SDL2_ttf/SDL_ttf.h>
#endif

#include <string>
#include <map>
#include <stdio.h>

#include "Vector2.h"

class TextureManager
{
public:
    void addTexture(const std::string &key, const std::string &file, SDL_Renderer* renderer);
    void removeTexture(const std::string &key);
    
    void addFont(const std::string &key, const std::string &file, int size, SDL_Renderer* renderer);
    void removeFont(const std::string &key);
    
    void renderTexture(const std::string &key, Vector2 position, Vector2 size, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void renderTextureFrame(const std::string &key, Vector2 position, Vector2 size, Vector2 frame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void renderTextureColor(const std::string &key, Vector2 position, Vector2 size, SDL_Renderer* renderer, SDL_Color color, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void renderTextureFrameColor(const std::string &key, Vector2 position, Vector2 size, Vector2 frame, SDL_Renderer* renderer, SDL_Color color, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void renderText(const std::string &key, const std::string &text, Vector2 position, int alignment, int fontSize, SDL_Renderer* renderer, SDL_Color col);
    SDL_Texture* textureText(const std::string &key, const std::string &text, int fontSize, SDL_Renderer* renderer, SDL_Color col);
    
private:
    std::map<std::string, SDL_Texture*> _textures;
    std::map<std::string, TTF_Font*> _fonts;
};

#endif
