#pragma once
#include <SDL.h>
#include <vector>

#include "Map.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Cherry.h"

// Classe principale del gioco: gestisce loop, SDL e oggetti
class Game {
public:
    Map map;         // mappa livello
    Pacman pacman;     // player
    Cherry cherry; // oggetto da raccogliere
    bool running = true;


    bool init();   // inizializzazione SDL e oggetti

    void clean();  // pulizia memoria SDL



    const  Uint8* handleEvents(); // input utente
    void update(float dt); // logica gioco
    void render(); // disegno

    

    void addGhost(Ghost ghost);
    void removeGhost(int x, int y);

  



    bool isEnemyAt(int x, int y);
 
    void setGhostsVulnerable();
    bool isGhostVulnerable(int x, int y);

    
	

    void moveCherry();
private:
   

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

   
    
 
    std::vector<Ghost> ghosts; // nemici
};