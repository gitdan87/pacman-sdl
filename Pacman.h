#pragma once
#include <SDL.h>
#include "Map.h"
#include "config.h"

// Player controllato da tastiera
class Pacman {
public:
    int x = 1;
    int y = 1;

    void handleInput(const Uint8* state, Map& map); // input tastiera
    void update(float dt, Map& map);
    void render(SDL_Renderer* r);

private:
    int dirX = 0; // direzione attuale
    int dirY = 0;

    int nextDirX = 0; // direzione richiesta (buffer input)
    int nextDirY = 0;

    float moveTimer = 0.0f;
    float moveInterval = PACMAN_MOVE_INTERVAL; // velocità movimento
};