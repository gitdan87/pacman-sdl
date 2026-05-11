#include "Pacman.h"
#include "Map.h"
#include "Game.h"

// input tastiera: memorizza direzione richiesta
void Pacman::handleInput(const Uint8* state, Map& map) {
    if (state[SDL_SCANCODE_UP]) { nextDirX = 0; nextDirY = -1; }
    if (state[SDL_SCANCODE_DOWN]) { nextDirX = 0; nextDirY = 1; }
    if (state[SDL_SCANCODE_LEFT]) { nextDirX = -1; nextDirY = 0; }
    if (state[SDL_SCANCODE_RIGHT]) { nextDirX = 1; nextDirY = 0; }
}

// logica movimento con buffer direzione
void Pacman::update(float dt, Map& map) {
    moveTimer += dt;

    if (moveTimer < moveInterval)
        return;

    moveTimer = 0.0f;

    // prova cambio direzione (anche se non ancora eseguita)
    int tryX = x + nextDirX;
    int tryY = y + nextDirY;

    if (!map.isWall(tryX, tryY)) {
        dirX = nextDirX;
        dirY = nextDirY;
    }

    // movimento effettivo
    int nx = x + dirX;
    int ny = y + dirY;

    if (!map.isWall(nx, ny)) {
        x = nx;
        y = ny;
    }

    
}

// disegno Pacman (giallo)
void Pacman::render(SDL_Renderer* r) {
    SDL_SetRenderDrawColor(r, 255, 255, 0, 255);

    SDL_Rect rect = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
    SDL_RenderFillRect(r, &rect);

    
}