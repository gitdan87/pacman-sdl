#pragma once
#include <SDL.h>

// dimensioni griglia
const int MAP_W = 20;
const int MAP_H = 15;
const int TILE_SIZE = 32;



// gestione mappa e collisioni
class Map {
    int defaultMap[MAP_H][MAP_W];
public:
    // true se la cella � un muro
    bool isWall(int x, int y);
    bool isBall(int x, int y);

    void setTile(int x, int y, int type);

    // disegna la mappa
    void render(SDL_Renderer* r);
};