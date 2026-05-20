#pragma once

// Dimensioni mappa
constexpr int TILE_SIZE = 32;   // dimensione in pixel di ogni cella
constexpr int MAP_W = 20;       // numero colonne
constexpr int MAP_H = 15;       // numero righe


// Frame rate
constexpr int FPS = 60;                         // frame target
constexpr int FRAME_TIME_MS = 1000 / FPS;       // ms per frame (~16ms)
constexpr float FIXED_DT = 1.0f/FPS;               // delta time fisso usato nella logica


// Colori
#define COLOR_BACKGROUND 0, 0, 0
#define COLOR_PACMAN 255, 255, 0
#define COLOR_GHOST 255, 0, 0
#define COLOR_GHOST_VULNERABLE 0, 0, 255
#define COLOR_CHERRY 255, 0, 0
#define COLOR_BALL 255, 255, 255
#define COLOR_WALL 0, 0, 255

// Gameplay
constexpr float PACMAN_MOVE_INTERVAL = 0.080f; // intervallo di movimento del player (secondi tra un passo e l’altro)
constexpr float GHOST_MOVE_INTERVAL = 0.100f; // intervallo di movimento dei fantasmi
constexpr float GHOST_VULNERABLE_TIME = 10.0f; // durata stato vulnerabile dei fantasmi (secondi)