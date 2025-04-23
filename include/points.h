#include "constants.h"

#ifndef POINTS_H

#define POINTS_H

typedef struct {
  float x;
  float y;
} Point;

typedef struct {
  Point *a;
  Point *b;
  Point *c;
} Triangle;

void move_matrix(int x_move, int y_move, int data[RESOLUTION][RESOLUTION]);
void rotate_triangle(Triangle *triangle, float theta);


#endif
