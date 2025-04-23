#include <SDL2/SDL.h>

#include "../include/points.h"
#include "../include/bresenham.h"
#include "../include/pixel.h"
#include "../include/span_filling.h"

#ifndef MAIN_H
#define MAIN_H

void initialize_sdl(SDL_Renderer **renderer, SDL_Window **window);
void destroy_sql(SDL_Renderer **renderer, SDL_Window **window);
void paint_sql(int data[RESOLUTION][RESOLUTION], SDL_Renderer **renderer);

#endif
