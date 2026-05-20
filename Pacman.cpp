#include "Pacman.h"
#include "Map.h"
#include "Game.h"
#include "config.h"

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

    //se la nuova posizione non è il muro
    if (!map.isWall(tryX, tryY)) {
        //imposto la nuova posizione
        x = tryX;
        y = tryY;
    }
    else {
        //se è il muro
        //non faccio nulla! -> il pacman si ferma
    }

    
}

// disegno Pacman (giallo)
void Pacman::render(SDL_Renderer* r) {
    SDL_SetRenderDrawColor(r, COLOR_PACMAN, 255);

	int startDeg, endDeg;
	if (nextDirX == 1) { startDeg = 30; endDeg = 330; } // destra
    else if(nextDirX == -1) { startDeg = 210; endDeg = 150; } // sinistra
    else if(nextDirY == -1) { startDeg = 300; endDeg = 240; } // su
    else if(nextDirY == 1) { startDeg = 120; endDeg = 60; } // giù
    else { startDeg = 30; endDeg = 330; } // fermo, default apertura
	SDL_RenderFillArc(r, x * TILE_SIZE + TILE_SIZE / 2, y * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, startDeg, endDeg);
    
}