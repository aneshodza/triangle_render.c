#include "../include/points.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void move_matrix(int x_move, int y_move, int data[RESOLUTION][RESOLUTION]) {
}

Point *get_centroid(Triangle *triangle) {
  float x = (triangle->a->x + triangle->b->x + triangle->c->x)/3;
  float y = (triangle->a->y + triangle->b->y + triangle->c->y)/3;

  Point *point = malloc(sizeof(Point));
  point->x = x;
  point->y = y;

  return point;
}

/*
 * This applies component-wise transformation
 * multiplications:
 * x_new = x * cos(theta) - y * sin(theta)
 * y_new = x * sin(theta) + y * cos(theta)
 */
void rotate_point(Point *point, float theta, Point *center_of_rotation) {
  float x = point->x;
  float cx = center_of_rotation->x;

  float y = point->y;
  float cy = center_of_rotation->y;

  point->x = (x - cx) * cos(theta) - (y - cy) * sin(theta) + cx;
  point->y = (x - cx) * sin(theta) + (y - cy) * cos(theta) + cy;
}

void rotate_triangle(Triangle *triangle, float theta) {
  Point *centroid = get_centroid(triangle);
  rotate_point(triangle->a, theta, centroid);
  rotate_point(triangle->b, theta, centroid);
  rotate_point(triangle->c, theta, centroid);
  free(centroid);
  centroid = NULL;
}

