#pragma once
#include <SDL.h>
#include "config.h"

class Map {
    int defaultMap[MAP_H][MAP_W];
public:
    Map();  // <-- AGGIUNTO

    bool isWall(int x, int y);
    bool isBall(int x, int y);
    void setTile(int x, int y, int type);
    void render(SDL_Renderer* r);
};