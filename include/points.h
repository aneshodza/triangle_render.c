#ifndef POINTS_H

#define POINTS_H

typedef struct {
  int x;
  int y;
} Point;

void move_point(int x_move, int y_move, int resolution, Point *A);

#endif
