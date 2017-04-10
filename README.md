# Space Game
## interstellar acquisition

Interstellar acquisition was one of my projects in 2014 which I never finished.

### Info
What does this project contain:
* State system
* Basic unit movement
* Memory leak in the menu (see fix below)

I stopped working on this project, and I don't remember why.

### Menu bugfix
The reason why I don't fix the menu memory leak is to learn from my past mistakes. And the memory leak appears on more places than just the menu, the button render also has this memory leak.

The memory leak appears to be in the render function of the menu render, something is created but doesn't get destroyed:
```cpp
void MenuState::render(SDL_Renderer *renderer, TextureManager &manager)
{
    /* ... */
    SDL_Color col;
    col.r = col.g = col.b = col.a = 255;
    manager.renderText("MainMenuText", "[EARLY-ALPHA]", Vector2(5, 720-16), 0, 8, renderer, col);
}
```
The problem is in renderText, we create a new texture for each text we want to render but we never free the texture. The buttons also have this problem.

To solve this just free the texture after rendering the text.
```cpp
SDL_DestroyTexture(tex);
```