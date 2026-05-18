#include "Cherry.h"
#include "config.h"

void Cherry::render(SDL_Renderer* r) {

	if (this->active == false) {
        return; // non disegnare se non attiva
    }

    SDL_Rect rect = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };

	SDL_SetRenderDrawColor(r, COLOR_CHERRY, 255);
	SDL_RenderFilledCircle(r, rect.x + TILE_SIZE / 2, rect.y + TILE_SIZE / 2, TILE_SIZE / 2 - 4);
}

bool Cherry::isActive() const {
	return active;
}

void Cherry::collect() {
	active = false;
}
