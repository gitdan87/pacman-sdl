#include "Ghost.h"
#include "Map.h"
#include <cstdlib>
#include "config.h"

Ghost::Ghost(int x, int y) {
     this->x = x;
     this->y = y;
}


// Aggiornamento del fantasma con AI: inseguimento di Pacman o fuga se vulnerabile
void Ghost::update(float dt, Map& map, int pacmanX, int pacmanY) {
    moveTimer += dt;

    if (moveTimer < moveInterval)
        return;

    moveTimer = 0.0f;

    struct Dir { int dx, dy; };

    Dir dirs[4] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    int bestDx = dirX;
    int bestDy = dirY;

    int bestScore = isVulnerable ? -1 : 999999;

    for (auto& d : dirs) {
        int nx = x + d.dx;
        int ny = y + d.dy;

        if (map.isWall(nx, ny))
            continue;

        int dist = abs(nx - pacmanX) + abs(ny - pacmanY);

        if (!isVulnerable) {
            // inseguimento: minimizza distanza
            if (dist < bestScore) {
                bestScore = dist;
                bestDx = d.dx;
                bestDy = d.dy;
            }
        }
        else {
            // fuga: massimizza distanza
            if (dist > bestScore) {
                bestScore = dist;
                bestDx = d.dx;
                bestDy = d.dy;
            }
        }
    }

    dirX = bestDx;
    dirY = bestDy;

    int nx = x + dirX;
    int ny = y + dirY;

    if (!map.isWall(nx, ny)) {
        x = nx;
        y = ny;
    }

    if (isVulnerable) {
        vulnerableTimer -= dt;
        if (vulnerableTimer <= 0)
            isVulnerable = false;
    }
}

// disegno fantasma (rosso)
void Ghost::render(SDL_Renderer* r) {
    if (isVulnerable) {
        SDL_SetRenderDrawColor(r, COLOR_GHOST_VULNERABLE, 255);
    }
    else {
        SDL_SetRenderDrawColor(r, COLOR_GHOST, 255);
    }

     SDL_Rect rect = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
     SDL_RenderFillRect(r, &rect);
}

void Ghost::setVulnerable() {
     isVulnerable = true;
     vulnerableTimer = GHOST_VULNERABLE_TIME; // durata vulnerabilità in secondi
}

bool Ghost::getVulnerable() const {
     return isVulnerable;
}