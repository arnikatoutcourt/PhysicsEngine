
#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "utils.h"

typedef enum {
  CIRCLE,
  SQUARE
} ColliderType;

typedef struct {
  ColliderType Type;
} Collider;

typedef struct {
  Position center;
  double radius;
} CircleCollider;

typedef struct {
  Vector borders[4];
  Position center;
} SquareCollider;

bool is_square_colliding(SquareCollider a, SquareCollider b);

#endif
