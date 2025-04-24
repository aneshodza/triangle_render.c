#include "../include/bresenham.h"

int bresenham(Point p0, Point p1, Point* output) {
  int x0 = (int)roundf(p0.x);
  int y0 = (int)roundf(p0.y);
  int x1 = (int)roundf(p1.x);
  int y1 = (int)roundf(p1.y);

  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);

  int sx = (x0 < x1) ? 1 : -1;
  int sy = (y0 < y1) ? 1 : -1;

  int err = dx - dy;
  int i = 0;

  while (1) {
    if (y0 == 0 && x0 != 0) {
      // TODO: Fix this error
    }
    output[i++] = (Point){x0, y0};
    if (x0 == x1 && y0 == y1) break;

    int e2 = 2 * err;
    if (e2 > -dy) { err -= dy; x0 += sx; }
    if (e2 < dx)  { err += dx; y0 += sy; }
  }

  return i;
}
