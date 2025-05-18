#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "shape.h"
#include "collisions.h"

void step(double dt, Object objects[], int nobj) {
    for (int i=0; i<nobj; i++) {
    objects[i].force = v_add(objects[i].force, v_mult(*grav(), objects[i].mass)); // apply gravity
    objects[i].velocity = v_add(objects[i].velocity, v_mult(v_div(objects[i].force, objects[i].mass), dt)); // apply force to velocity
    objects[i].position = p_v_apply(objects[i].position, v_mult(objects[i].velocity, dt)); // apply velocity to position 
    objects[i].force = *null_v(); // reset the force
  }
}

int main()
{
  SquareCollider a;
  Position s1_corners[4] = {
        {1.0, 1.0},
        {3.0, 1.0},
        {3.0, 3.0},
        {1.0, 3.0}
  };
  create_square(s1_corners, a.borders);
  SquareCollider b;
  Position s2_corners[4] = {
        {2.0, 1.0},
        {4.0, 1.0},
        {4.0, 3.0},
        {2.0, 3.0}
  };
  create_square(s2_corners, b.borders); 
  printf("Collision : %d\n", is_square_colliding(a, b));

  return EXIT_SUCCESS;
}
