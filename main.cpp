#include "Game.h"
#include "config.h"

int main(int argc, char* argv[]) {
    
    Game g;
    g.init();

    // posizione iniziale player
    g.pacman.x = 3;
    g.pacman.y = 1;

    // creazione dei ghosts iniziali
    Ghost fantasma1(10, 10);
    g.addGhost(fantasma1); 

    Ghost fantasma2(15, 5);
    g.addGhost(fantasma2); 

     
    while (g.running) {
        g.handleEvents();
        g.updatePacman();

		//termina il gioco se Pacman collide con un fantasma
        if (g.isEnemyAt(g.pacman.x, g.pacman.y)) {
            g.running = false;
        }

        g.updateGhosts();
        g.render();
    }

    g.clean();
    return 0;
}