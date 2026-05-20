#pragma once

#include <SDL.h>
#include <cmath>

void SDL_RenderFillCircle(SDL_Renderer* renderer, int cx, int cy, int radius);
void SDL_RenderFillArc(SDL_Renderer* renderer, int cx, int cy, int radius,int startDeg, int endDeg);