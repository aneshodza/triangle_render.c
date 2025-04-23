#include <SDL2/SDL.h>
#include "points.h"
#include "bresenham.h"
#include "constants.h"

#ifndef PIXEL_H

#define PIXEL_H

void light(SDL_Renderer* renderer, int x, int y);
void dark(SDL_Renderer* renderer, int x, int y);
void mark_line(const Point A, const Point B, int data[RESOLUTION][RESOLUTION]);

#endif
