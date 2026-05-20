# 1) Inizializzazione

spiegare:
- l'esecuzione "dall'alto al basso"
- introduzione a "variabile"
- parole chiave ( init, render, clean ) 
- cos'è il while e perchè serve in un gioco


```cpp
    Game g;
    g.init();

    while (g.running) {
        g.render();
    }

    g.clean();
```

# 2) Posizione del pacmam
spiegare che dentro ad una variabile ce ne può stare un altra

impostiamo la posizione del pacman

```cpp
    Game g;
    g.init();

--> // posizione iniziale player
--> game.pacman.x = 1;
--> game.pacman.y = 1;
    

    while (g.running) {
        g.render();
    }

    g.clean();
```
# 3) Movimento
spiegare che le cose non si muovono fino a che non lo programmiamo noi

```cpp
    Game g;
    g.init();

    // posizione iniziale player
    game.pacman.x = 1;
    game.pacman.y = 1;
    

    while (g.running) {
-->     g.handleEvents();
-->     g.updatePacman();

        g.render();
    }

    g.clean();
```

# 4) Personalizzare la mappa
spiegare che:
- nei file già preparati ci sono altri pezzi di codice.
- che sotto ai giochi/programmi ci sono numeri

cose da fare:
- Andare nel file "Map.cpp", e decommentare la mappa già presente a riga 8 
- personalizzare a piacare la mappa mettendo:
    -   1 = muro
    -   0 = spazio vuoto
    -   2 = pallino da mangiare

mappa solo bordi:
```cpp
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        

```

# 5) Aggiungiamo i fantasmi

mostrare prima il codice con solo i fantasmi aggiunti e poi inserire `g.updateGhosts();`

```cpp
    Game g;
    g.init();

    // posizione iniziale player
    game.pacman.x = 1;
    game.pacman.y = 1;
    

    // creazione dei ghosts iniziali
--> Ghost fantasma1(10, 10);
--> g.addGhost(fantasma1); 

--> Ghost fantasma2(15, 5);
--> g.addGhost(fantasma2); 



    while (g.running) {
        g.handleEvents();
        g.updatePacman();

-->     g.updateGhosts();
        g.render();
    }

    g.clean();
```

# 6) Logica del gioco

spiegare come possiamo modificare la logica a piacimento

```cpp
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

-->     //termina il gioco se Pacman collide con un fantasma
-->     if (g.isEnemyAt(g.pacman.x, g.pacman.y)) {
-->         g.running = false;
-->     }

        g.updateGhosts();
        g.render();
    }

    g.clean();
```

# 7) Ciliegia
    
ragionare su dove aggiungere i pezzi di codice per aggiungere funzionalità.
Abbiamo aggiunto la ciliegia e impostiamo i Ghost "vulnerabili" ma dobbiamo ancora modificare il codice che gesisce la morte se tocchiamo un nemico

```cpp
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

--> g.moveCherry();
    while (g.running) {
        g.handleEvents();
        g.updatePacman();

        //termina il gioco se Pacman collide con un fantasma
        if (g.isEnemyAt(g.pacman.x, g.pacman.y)) {
            g.running = false;
        }

-->     if (g.pacman.x == g.cherry.x && g.pacman.y == g.cherry.y ) {
-->         g.cherry.collect(); // raccogli la ciliegia
-->         g.setGhostsVulnerable();
-->         g.moveCherry(); // posiziona una nuova ciliegia
-->     }


        g.updateGhosts();
        g.render();
    }

    g.clean();
```



# 8) Mangiare i nemici
    
ragionare su dove aggiungere i pezzi di codice per aggiungere funzionalità.
Abbiamo aggiunto la ciliegia e impostiamo i Ghost "vulnerabili" ma dobbiamo ancora modificare il codice che gesisce la morte se tocchiamo un nemico

```cpp
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

    g.moveCherry();
    while (g.running) {
        g.handleEvents();
        g.updatePacman();

        //termina il gioco se Pacman collide con un fantasma
        if (g.isEnemyAt(g.pacman.x, g.pacman.y)) {
-->         if (g.isGhostVulnerable(g.pacman.x, g.pacman.y)) {
-->             g.removeGhost(g.pacman.x, g.pacman.y);    // rimuovi il fantasma vulnerabile
-->         }
-->         else{
-->             g.running = false; // termina il gioco se Pacman viene catturato
-->         }
        }

        if (g.pacman.x == g.cherry.x && g.pacman.y == g.cherry.y ) {
            g.cherry.collect(); // raccogli la ciliegia
            g.setGhostsVulnerable();
            g.moveCherry(); // posiziona una nuova ciliegia
        }


        g.updateGhosts();
        g.render();
    }

    g.clean();
```

# 9) Implementiamo le palline

Torniamo nella map.cpp ed inseriamo che al posto degli 0 mettiamo dei 2

i pallini saranno presenti ma non saranno ancora mangiabili, occorre modificare il codice:

```cpp
    Game g;
    g.init();
--> int punteggio=0;

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
            else{
                g.running = false; // termina il gioco se Pacman viene catturato
            }
        }

        if (g.pacman.x == g.cherry.x && g.pacman.y == g.cherry.y ) {
            g.cherry.collect(); // raccogli la ciliegia
            g.setGhostsVulnerable();
            g.moveCherry(); // posiziona una nuova ciliegia
        }

-->     if (g.map.isBall(g.pacman.x, g.pacman.y))
-->     {
-->         g.map.setTile(g.pacman.x, g.pacman.y, 0); // rimuovi la pallina
-->         punteggio = punteggio +1;
-->     }

        g.updateGhosts();
        g.render();
    }

    g.clean();
```


# TODO:
- provare a modificare i colori
- modificare le velocità
- visualizzare il punteggio
```cpp
std::string  scoreText = "Pacman - punteggio: " + std::to_string(punteggio);
g.setWindowTitle(scoreText.c_str()); // cambia titolo finestra
```

# PRO
gestione di una pressione di un tasto nel main per ad esempio creare un "cheat" che ci fa mangiare i ghost anche senza mangiare la ciliegia ( premendo spazioo)
```cpp
KeyboardState stato = g.handleEvents();
if (stato[SDL_SCANCODE_SPACE])
    g.setGhostsVulnerable();
```


# TOTALE

```cpp
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
        }
        g.updateGhosts();
        g.render();
    }

    g.clean();
    return 0;
```

