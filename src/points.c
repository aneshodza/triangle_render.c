#include "../include/points.h"

void move_point(int x_move, int y_move, int resolution, Point *A) {
  A->x += x_move;
  A->y += y_move;
}

