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

void translate_matrix(Triangle *triangle, Point *point, int reverse);
void rotate_triangle(Triangle *triangle, float theta);

#endif
