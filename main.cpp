#include "Game.h"
#include "config.h"
#include <string>

int main(int argc, char* argv[]) {
    
    Game g;
    g.init();
    int punteggio = 0;

    // posizione iniziale player
    g.pacman.x = 3;
    g.pacman.y = 1;

    // creazione dei ghosts iniziali
    Ghost fantasma1(10, 10);
    g.addGhost(fantasma1); 

    Ghost fantasma2(15, 5);
    g.addGhost(fantasma2); 

    g.moveCherry();
    while (g.running) {
        g.handleEvents();
        g.updatePacman();

		//termina il gioco se Pacman collide con un fantasma
        if (g.isEnemyAt(g.pacman.x, g.pacman.y)) {
            if (g.isGhostVulnerable(g.pacman.x, g.pacman.y)) {
                g.removeGhost(g.pacman.x, g.pacman.y);    // rimuovi il fantasma vulnerabile
            }
            else {
                g.running = false; // termina il gioco se Pacman viene catturato
            }
        }
        

        if (g.pacman.x == g.cherry.x && g.pacman.y == g.cherry.y ) {
            g.cherry.collect(); // raccogli la ciliegia
            g.setGhostsVulnerable();
            g.moveCherry(); // posiziona una nuova ciliegia
        }

        if (g.map.isBall(g.pacman.x, g.pacman.y))
        {
            g.map.setTile(g.pacman.x, g.pacman.y, 0); // rimuovi la pallina
            punteggio = punteggio + 1;
			std::string  scoreText = "Pacman - punteggio: " + std::to_string(punteggio);
			g.setWindowTitle(scoreText.c_str()); // cambia titolo finestra
        }
        g.updateGhosts();
        g.render();
    }

    g.clean();
    return 0;
}