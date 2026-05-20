#include "Game.h"
#include "config.h"

int main(int argc, char* argv[]) {
    
    Game g;
    g.init();

    // posizione iniziale player
    g.pacman.x = 3;
    g.pacman.y = 1;

    Ghost fantasma1(10, 10);
    g.addGhost(fantasma1); // creazione dei ghosts iniziali

    Ghost fantasma2(15, 5);
    g.addGhost(fantasma2); // creazione dei ghosts iniziali

     
    while (g.running) {
        g.handleEvents();
        g.updatePacman();

        g.updateGhosts();
        g.render();
    }

    g.clean();
    return 0;
}