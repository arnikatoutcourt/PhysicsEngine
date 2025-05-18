#include "vector.h"
#include "shape.h"

void create_square(Position pos[4], Vector square[4]) {
  square[0] = create_vector(pos[0], pos[1]);
  square[1] = create_vector(pos[1], pos[2]);
  square[2] = create_vector(pos[2], pos[3]);
  square[3] = create_vector(pos[3], pos[0]); 
}
