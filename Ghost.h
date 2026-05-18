#pragma once
#include <SDL.h>
#include "Map.h"
#include "config.h"

// Fantasma: movimento semplice casuale
class Ghost {
public:
    int x = 0;
    int y = 0;

    void update(float dt, Map& map, int pacmanX, int pacmanY);
    void render(SDL_Renderer* r);

    Ghost(int x, int y);

    void setVulnerable();
    bool getVulnerable() const;


private:
    int dirX = 1; // direzione corrente X
    int dirY = 0; // direzione corrente Y

    float moveTimer = 0.0f;      // timer movimento
    float moveInterval = 1.0f;  // velocit� movimento

    bool isVulnerable = false; // stato vulnerabile 

	float vulnerableTimer = 0; // timer stato vulnerabile
};