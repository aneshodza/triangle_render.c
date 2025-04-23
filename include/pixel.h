#include <SDL2/SDL.h>
#include "points.h"
#include "bresenham.h"

#ifndef PIXEL_H

#define PIXEL_H

#define PIXEL_SIZE 1
#define PIXEL_ON 1
#define RESOLUTION 500
#define MAX_STRAIGHT ((RESOLUTION * 3) / 2)

void light(SDL_Renderer* renderer, int x, int y);
void dark(SDL_Renderer* renderer, int x, int y);
void mark_line(const Point A, const Point B, int data[RESOLUTION][RESOLUTION]);

#endif
