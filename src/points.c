#include "../include/points.h"

void translate_matrix(Triangle *triangle, Point *point, int reverse) {
  float dx = reverse ? -point->x : point->x;
  float dy = reverse ? -point->y : point->y;

  triangle->a->x -= dx;
  triangle->b->x -= dx;
  triangle->c->x -= dx;

  triangle->a->y -= dy;
  triangle->b->y -= dy;
  triangle->c->y -= dy;
}

Point *get_centroid(Triangle *triangle) {
  float x = (triangle->a->x + triangle->b->x + triangle->c->x)/3;
  float y = (triangle->a->y + triangle->b->y + triangle->c->y)/3;

  Point *point = malloc(sizeof(Point));
  point->x = x;
  point->y = y;

  return point;
}

void transform_point(Point *point, float tf_matrix[2][2]) {
    float x = point->x;
    float y = point->y;
    point->x = tf_matrix[0][0] * x + tf_matrix[0][1] * y;
    point->y = tf_matrix[1][0] * x + tf_matrix[1][1] * y;
}

void transform_triangle(Triangle *triangle, float m[2][2]) {
    transform_point(triangle->a, m);
    transform_point(triangle->b, m);
    transform_point(triangle->c, m);
}

void rotate_triangle(Triangle *triangle, float theta) {
  Point *centroid = get_centroid(triangle);
  translate_matrix(triangle, centroid, false);

  float rotation_matrix[2][2] = {
    {cos(theta), -sin(theta)},
    {sin(theta), cos(theta)}
  };
  transform_triangle(triangle, rotation_matrix);

  translate_matrix(triangle, centroid, true);

  free(centroid);
  centroid = NULL;
}

int is_on_screen(Point* point) {
    return point->x >= 0 &&
           point->x < RESOLUTION &&
           point->y >= 0 &&
           point->y < RESOLUTION;
}
