#include "../include/pixel.h"

void paint(SDL_Renderer* renderer, int x, int y, int white) {
  int color = 255*white;
  SDL_SetRenderDrawColor(renderer, color, color, color, 255);
  SDL_Rect rect = { x * PIXEL_SIZE, y * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE };
  SDL_RenderFillRect(renderer, &rect);
}

void light(SDL_Renderer* renderer, int x, int y) {
  paint(renderer, x, y, 1);
}

void dark(SDL_Renderer* renderer, int x, int y) {
  paint(renderer, x, y, 0);
}

void mark_line(const Point A, const Point B, int data[RESOLUTION][RESOLUTION]) {
  Point line[MAX_STRAIGHT] = {0};
  int len = bresenham(A, B, line);

  for (int i = 0; i < len; ++i) {
    data[line[i].y][line[i].x] = PIXEL_ON;
  }
}
