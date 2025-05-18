
#ifndef UTILS_H
#define UTILS_H

#include "vector.h"

typedef struct {
  Vector position;
  Vector scale;
  Quaternion rotation;
} Transform;

bool find_intersection(Vector a, Vector b, Position* intersection);

#endif
