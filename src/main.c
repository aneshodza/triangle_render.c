#include "../include/main.h"

int main() {
  Point A = {100, 150};
  Point B = {300, 250};
  Point C = {450, 100};

  Triangle triangle = { &A, &B, &C };

  SDL_Renderer *renderer;
  SDL_Window *window;
  initialize_sdl(&renderer, &window);

  SDL_Event e;

  int running = 1;
  while (running) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) running = 0;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int data[RESOLUTION][RESOLUTION] = {0};

    mark_line(A, B, data);
    mark_line(A, C, data);
    mark_line(B, C, data);
    span_filling(data);

    rotate_triangle(&triangle, 0.01);

    paint_sdl(data, &renderer);

    SDL_RenderPresent(renderer);
    SDL_Delay(16);
  }

  destroy_sdl(&renderer, &window);
  return 0;
}

void initialize_sdl(SDL_Renderer **renderer, SDL_Window **window) {
  SDL_Init(SDL_INIT_VIDEO);
  *window = SDL_CreateWindow("Triangle",
                             SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                             RESOLUTION * PIXEL_SIZE, RESOLUTION * PIXEL_SIZE, 0);
  *renderer = SDL_CreateRenderer(*window, -1, 0);
}

void destroy_sdl(SDL_Renderer **renderer, SDL_Window **window) {
  SDL_DestroyRenderer(*renderer);
  SDL_DestroyWindow(*window);
  SDL_Quit();
}

void paint_sdl(int data[RESOLUTION][RESOLUTION], SDL_Renderer **renderer) {
  for (int y = 0; y < RESOLUTION; y++) {
    for (int x = 0; x < RESOLUTION; x++) {
      if (data[y][x] == PIXEL_ON) {
        light(*renderer, x, y);
      } else {
        dark(*renderer, x, y);
      }
    }
  }
}
