#include "Game.h"

int main(int argc, char* argv[]) {
    Game game;

    game.init();

    // posizione iniziale player
    game.pacman.x = 1;
    game.pacman.y = 1;
    

    game.map.setTile(0, 0, 1); // esempio: aggiungo un muro in posizione (0,0)
    game.map.setTile(0, 1, 1);
    game.map.setTile(0, 2, 1); 

    game.map.setTile(0, 3, 2);


    Ghost g1(10, 10);
    game.addGhost(g1); // creazione dei ghosts iniziali
        
    Ghost g2(15, 5);
    game.addGhost(g2); // creazione dei ghosts iniziali
    
    //Ghost g3(16, 5);
    //game.addGhost(g3); // creazione dei ghosts iniziali

    
	game.moveCherry(); // posiziona la ciliegia iniziale

    while (game.running) {
        const Uint8* state= game.handleEvents();
        game.updatePacman(0.16f); // dt fisso ~60 FPS

		if (game.isEnemyAt(game.pacman.x, game.pacman.y)) {
			if (game.isGhostVulnerable(game.pacman.x, game.pacman.y)) {
                // rimuovi il fantasma vulnerabile
				game.removeGhost(game.pacman.x, game.pacman.y);
            }
            else
                game.running = false; // termina il gioco se Pacman viene catturato
        }
        if (game.map.isBall(game.pacman.x, game.pacman.y))
        {
			game.map.setTile(game.pacman.x, game.pacman.y, 0); // rimuovi la pallina
        }

        game.updateGhosts(0.16f); // dt fisso ~60 FPS


		if (game.pacman.x == game.cherry.x && game.pacman.y == game.cherry.y && game.cherry.isActive()) {
            game.cherry.collect(); // raccogli la ciliegia
            game.setGhostsVulnerable();
            game.moveCherry(); // posiziona una nuova ciliegia
        }


        

        game.render();
        SDL_Delay(16);
    }
    game.clean();

    return 0;

}