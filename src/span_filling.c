#include "../include/pixel.h"

void span_filling(int data[RESOLUTION][RESOLUTION]) {
  for (int i = 0; i< RESOLUTION; i++) {
    int first = -1;
    int last = -1;
    for (int j = 0; j< RESOLUTION; j++) {
      if (data[i][j] == PIXEL_ON) {
        if (first == -1) {
          first = j;
        }
        last = j;
      }
    }

    for (int j = first; j < last; j++) {
      data[i][j] = PIXEL_ON;
    }
  }
}
