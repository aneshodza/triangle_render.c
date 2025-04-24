#include "constants.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
int is_on_screen(Point* point);

#endif
