#include "collisions.h"

bool is_square_colliding(SquareCollider a, SquareCollider b) {
  Position intersect;
  for(int i=0;i<4;i++) {
    for(int j=0;j<4;i++) {
      if(find_intersection(a.borders[i], b.borders[j], &intersect)) {
        return true;
      }
    }
  }
  return false; 
} 
