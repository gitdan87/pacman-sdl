#include "Map.h"
#include "utility.h"
#include "config.h"
// mappa statica: 1 = muro, 0 = vuoto
//int defaultMap[MAP_H][MAP_W] = {
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//    {1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1},
//    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
//    {1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1},
//    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1},
//    {1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1},
//    {1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
//    {1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1},
//    {1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1},
//    {1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1},
//    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
//    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//};




// collisione: true se muro o fuori mappa
bool Map::isWall(int x, int y) {
    if (x < 0 || y < 0 || x >= MAP_W || y >= MAP_H)
        return true;

    return defaultMap[y][x] == 1;
}

// collisione: true se muro o fuori mappa
bool Map::isBall(int x, int y) {
    if (x < 0 || y < 0 || x >= MAP_W || y >= MAP_H)
        return true;

    return defaultMap[y][x] == 2;
}

// rendering griglia
void Map::render(SDL_Renderer* r) {
     for (int y = 0; y < MAP_H; y++) {
         for (int x = 0; x < MAP_W; x++) {

             if (defaultMap[y][x] == 2)
             {
                 SDL_SetRenderDrawColor(r, 255, 255, 255, 255); // muro
				 SDL_RenderFilledCircle(r, x * TILE_SIZE + TILE_SIZE / 2, y * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 4);
                 continue;
             }
             if (defaultMap[y][x] == 1)
                 SDL_SetRenderDrawColor(r, 0, 0, 255, 255); // muro
             else if (defaultMap[y][x] == 0)
                 SDL_SetRenderDrawColor(r, BACKGROUND_COLOR, 255);   // vuoto
            
             SDL_Rect rect = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
             SDL_RenderFillRect(r, &rect);


         }
     }
}

void Map::setTile(int x, int y, int type) {
     if (x < 0 || y < 0 || x >= MAP_W || y >= MAP_H)
         return;
     this->defaultMap[y][x] = type;
}