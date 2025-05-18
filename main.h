
#ifndef MAIN_H
#define MAIN_H

#include "vector.h"

/**
  * This function computes a step in the physics engine.
  *
  * @param dt: DeltaTime. It's the time between two frames
  * @param objects[]: list of Object to apply physics
  * @param nobj: length of objects[]
  */
void step(double dt, Object objects[], int nobj);

#endif
