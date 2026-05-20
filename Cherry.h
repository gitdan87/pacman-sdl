#pragma once
#include <SDL.h>
#include "Map.h"
#include "utility.h"

class Cherry
{
public:
    int x = -1;
    int y = -1;
    

    void render(SDL_Renderer* r);
    bool isActive() const;
    void collect();
};

