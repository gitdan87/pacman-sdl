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

# TOTALE - TODO

```cpp
 Game game;

 game.init();

 // posizione iniziale player
 game.pacman.x = 1;
 game.pacman.y = 1;


 //game.map.setTile(0, 0, 1); // esempio: aggiungo un muro in posizione (0,0)
 //game.map.setTile(0, 1, 1);
 //game.map.setTile(0, 2, 1); 

 //game.map.setTile(0, 3, 2);


 Ghost g1(10, 10);
 game.addGhost(g1); // creazione dei ghosts iniziali

 Ghost g2(15, 5);
 game.addGhost(g2); // creazione dei ghosts iniziali


 game.moveCherry(); // posiziona la ciliegia iniziale

 while (game.running) {
     const Uint8* state = game.handleEvents();
     game.updatePacman();

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

     game.updateGhosts();


     if (game.pacman.x == game.cherry.x && game.pacman.y == game.cherry.y && game.cherry.isActive()) {
         game.cherry.collect(); // raccogli la ciliegia
         game.setGhostsVulnerable();
         game.moveCherry(); // posiziona una nuova ciliegia
     }

     game.render();
 }
 game.clean();
 return 0;
```


# PRO

```cpp
KeyboardState stato = g.handleEvents();
if (stato[SDL_SCANCODE_SPACE])
    g.setGhostsVulnerable();
```