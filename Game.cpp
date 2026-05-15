#include "Game.h"
#include <algorithm>
#include "config.h"

// inizializzazione SDL e creazione finestra/render
bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;

    window = SDL_CreateWindow("Pacman",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        MAP_W*TILE_SIZE, MAP_H*TILE_SIZE, 0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

   
   
    return true;
}

// gestione input SDL
const  Uint8* Game::handleEvents() {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT)
            running = false;
    }

    // stato tastiera continuo
    const Uint8* state = SDL_GetKeyboardState(NULL);
    pacman.handleInput(state, map);

    return state;
}

// aggiornamento logica
void Game::updatePacman(float dt) {
    pacman.update(dt, map);
}

// aggiornamento logica
void Game::updateGhosts(float dt) {
    for (auto& g : ghosts)
        g.update(dt, map, pacman.x, pacman.y);
}


// rendering scena
void Game::render() {
    SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR, 255);
    SDL_RenderClear(renderer);

    map.render(renderer);
    pacman.render(renderer);

    for (auto& g : ghosts)
        g.render(renderer);

	cherry.render(renderer);

    SDL_RenderPresent(renderer);
}

bool Game::isGhostVulnerable(int x, int y)
{
    for (const auto& g : ghosts) {
        if (g.x == x && g.y == y) {
            return g.getVulnerable(); // restituisce lo stato vulnerabile del fantasma
        }
    }
    return false; // nessun fantasma in quella posizione
}

void Game::moveCherry()
{
    // Posizione casuale per la ciliegia
    int x, y;
    do {
        x = rand() % MAP_W;
        y = rand() % MAP_H;
    } while (map.isWall(x, y) || (x == pacman.x && y == pacman.y)); // evita muri e posizione di Pacman
    cherry.x = x;
    cherry.y = y;
    cherry.active = true; // rendi la ciliegia attiva
}

// cleanup SDL
void Game::clean() {
     SDL_DestroyRenderer(renderer);
     SDL_DestroyWindow(window);
     SDL_Quit();
}

void Game::addGhost(Ghost ghost) {
     ghosts.push_back(ghost);
}

void Game::removeGhost(int x, int y) {
     ghosts.erase(std::remove_if(ghosts.begin(), ghosts.end(),
         [x, y](const Ghost& g) { return g.x == x && g.y == y; }),
         ghosts.end());
}

bool Game::isEnemyAt(int x, int y) {
     for (const auto& g : ghosts) {
         if (g.x == x && g.y == y)
             return true;
     }
     return false;
}



void Game::setGhostsVulnerable() {
     for (auto& g : ghosts) {
         g.setVulnerable();
     }
}