#include "../include/points.h"
#include <math.h>
#include <stdio.h>

void move_matrix(int x_move, int y_move, int data[RESOLUTION][RESOLUTION]) {
}

/*
 * This applies component-wise transformation
 * multiplications:
 * x_new = (x - rot_axis) * cos(theta) - (y - rot_axis) * sin(theta) + rot_axis
 * y_new = (x - rot_axis) * sin(theta) + (y - rot_axis) * cos(theta) + rot_axis
 */
void rotate_point(Point *point, float theta) {
  point->x = (point->x - RESOLUTION/2.) * cos(theta) - (point->y - RESOLUTION/2.) * sin(theta) + RESOLUTION/2.;
  point->y = (point->x - RESOLUTION/2.) * sin(theta) + (point->y - RESOLUTION/2.) * cos(theta) + RESOLUTION/2.;
  printf("Rotated point to (%f, %f)\n", point->x, point->y);
}

void rotate_triangle(Triangle *triangle, float theta) {
  rotate_point(triangle->a, theta);
  rotate_point(triangle->b, theta);
  rotate_point(triangle->c, theta);
}

