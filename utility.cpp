#include "utility.h"
#include <cmath>

void SDL_RenderFillCircle(SDL_Renderer* renderer, int cx, int cy, int radius)
{
    for (int dy = -radius; dy <= radius; dy++)
    {
        int dx = (int)std::sqrt(radius * radius - dy * dy);

        SDL_RenderDrawLine(renderer,
            cx - dx, cy + dy,
            cx + dx, cy + dy);
    }
}

void SDL_RenderFillArc(SDL_Renderer* renderer, int cx, int cy, int radius, int startDeg, int endDeg)
{
    const double PI = 3.14159265358979323846;
    double startRad = startDeg * PI / 180.0;
    double endRad = endDeg * PI / 180.0;

    for (int dy = -radius; dy <= radius; dy++)
    {
        for (int dx = -radius; dx <= radius; dx++)
        {
            double distance = std::sqrt(dx * dx + dy * dy);

            if (distance <= radius)
            {
                double angle = std::atan2(dy, dx);

                if (angle < 0)
                    angle += 2 * PI;

                double normalizedStart = startRad;
                double normalizedEnd = endRad;

                if (normalizedStart < 0)
                    normalizedStart += 2 * PI;
                if (normalizedEnd < 0)
                    normalizedEnd += 2 * PI;

                bool inArc = false;
                if (normalizedStart <= normalizedEnd)
                {
                    inArc = (angle >= normalizedStart && angle <= normalizedEnd);
                }
                else
                {
                    inArc = (angle >= normalizedStart || angle <= normalizedEnd);
                }

                if (inArc)
                {
                    SDL_RenderDrawPoint(renderer, cx + dx, cy + dy);
                }
            }
        }
    }
}
