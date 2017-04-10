#include "TextureManager.h"

void TextureManager::addTexture(const std::string &key, const std::string &file, SDL_Renderer *renderer)
{
    SDL_Texture* temp = IMG_LoadTexture(renderer, file.c_str());
    if(temp == nullptr)
    {
        std::printf("Image Load Error: %s\n", IMG_GetError());
    }
    _textures[key] = temp;
}

void TextureManager::removeTexture(const std::string &key)
{
    if(_textures.find(key) != _textures.end())
    {
        SDL_DestroyTexture(_textures[key]);
        _textures.erase(key);
    }
}

void TextureManager::addFont(const std::string &key, const std::string &file, int size, SDL_Renderer *renderer)
{
    TTF_Font* temp = TTF_OpenFont(file.c_str(), size);
    if(temp == nullptr)
    {
        std::printf("Font Load Error: %s\n", TTF_GetError());
    }
    _fonts[key] = temp;
}

void TextureManager::removeFont(const std::string &key)
{
    if(_fonts.find(key) != _fonts.end())
    {
        TTF_CloseFont(_fonts[key]);
        _fonts.erase(key);
    }
}

void TextureManager::renderTexture(const std::string &key, Vector2 position, Vector2 size, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect src;
    SDL_Rect dst;
    
    src.x = 0;
    src.y = 0;
    src.w = dst.w = size.x;
    src.h = dst.h = size.y;
    dst.x = position.x;
    dst.y = position.y;
    
    SDL_RenderCopyEx(renderer, _textures[key], &src, &dst, 0.0, NULL, flip);
}

void TextureManager::renderTextureFrame(const std::string &key, Vector2 position, Vector2 size, Vector2 frame, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect src;
    SDL_Rect dst;
    
    src.x = frame.x * size.x;
    src.y = frame.y * size.y;
    src.w = dst.w = size.x;
    src.h = dst.h = size.y;
    dst.x = position.x;
    dst.y = position.y;
    
    SDL_RenderCopyEx(renderer, _textures[key], &src, &dst, 0.0, NULL, flip);
    
}

void TextureManager::renderTextureColor(const std::string &key, Vector2 position, Vector2 size, SDL_Renderer* renderer, SDL_Color color, SDL_RendererFlip flip)
{
	SDL_Texture *tempTex = _textures[key];
	SDL_SetTextureColorMod(tempTex, color.r, color.g, color.b);

	SDL_Rect src;
    SDL_Rect dst;
    
    src.x = 0;
    src.y = 0;
    src.w = dst.w = size.x;
    src.h = dst.h = size.y;
    dst.x = position.x;
    dst.y = position.y;
    
    SDL_RenderCopyEx(renderer, tempTex, &src, &dst, 0.0, NULL, flip);
}

void TextureManager::renderTextureFrameColor(const std::string &key, Vector2 position, Vector2 size, Vector2 frame, SDL_Renderer* renderer, SDL_Color color, SDL_RendererFlip flip)
{
	SDL_Texture *tempTex = _textures[key];
	SDL_SetTextureColorMod(tempTex, color.r, color.g, color.b);
	
	SDL_Rect src;
    SDL_Rect dst;
    
    src.x = frame.x * size.x;
    src.y = frame.y * size.y;
    src.w = dst.w = size.x;
    src.h = dst.h = size.y;
    dst.x = position.x;
    dst.y = position.y;
    
    SDL_RenderCopyEx(renderer, tempTex, &src, &dst, 0.0, NULL, flip);
}

void TextureManager::renderText(const std::string &key, const std::string &text, Vector2 position, int alignment, int fontSize, SDL_Renderer *renderer, SDL_Color col)
{
    SDL_Texture *tex = textureText(key, text, fontSize, renderer, col);
    int w, h;
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    
    /* Alignment */
    Vector2 calculatedPos;
    if(alignment == 0)
    {
        // left
        calculatedPos.x = position.x;
        calculatedPos.y = position.y;
    }
    else
    {
        // from origin
        calculatedPos.x = position.x - w/2;
        calculatedPos.y = position.y - h/2;
    }
    
    SDL_Rect dstRect;
    SDL_Rect srcRect;
    
    srcRect.x = 0;
    srcRect.y = 0;
    dstRect.x = calculatedPos.x;
    dstRect.y = calculatedPos.y;
    srcRect.w = dstRect.w = w;
    srcRect.h = dstRect.h = h;
    
    SDL_RenderCopyEx(renderer, tex, &srcRect, &dstRect, 0.0, NULL, SDL_FLIP_NONE);
}

SDL_Texture* TextureManager::textureText(const std::string &key, const std::string &text, int fontSize, SDL_Renderer* renderer, SDL_Color col)
{
    SDL_Surface *surf = TTF_RenderText_Blended(_fonts[key], text.c_str(), col);
    if(surf == nullptr)
    {
        std::printf("Surface Creation Error: %s\n", SDL_GetError());
        return nullptr;
    }
    
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
    if(tex == nullptr)
    {
        SDL_FreeSurface(surf);
        std::printf("Texture Creation Error: %s\n", SDL_GetError());
        return nullptr;
    }
    
    SDL_FreeSurface(surf);
    return tex;
}























