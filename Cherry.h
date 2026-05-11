#pragma once
#include <SDL.h>
#include "Map.h"
#include "utility.h"

class Cherry
{
public:
    int x = 0;
    int y = 0;
    bool active = false;

    void render(SDL_Renderer* r);
    bool isActive() const;
    void collect();
};

