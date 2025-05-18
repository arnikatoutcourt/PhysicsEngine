
#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stdint.h>
#include <math.h>

/**
  * This structure represents a position (x,y)
  * in Euclidian Space.
  */
typedef struct {
  double x;
  double y;
} Position;

/**
  * This structure represents a Vector (start, end)
  * in Euclidian Space.
  */
typedef struct {
  Position start;
  Position end;
  double dx;
  double dy;
} Vector;

//TODO: Implement Quaternions
/**
 * This structure represents a Quaternion (4D object).
 * Used mostly in rotations.
 */
typedef struct {
} Quaternion;

/**
  * This structure represents an Object. It has :
  * @param position: the position
  * @param velocity: it's velocity
  * @param force: the resultant of the forces applied to it
  * @param mass: the mass of the object
  */
typedef struct {
  Position position;
  Vector velocity;
  Vector force;
  double mass;
} Object;


/**
  * This function creates a Vector, and more importantly,
  * creates it's dx and dy.
  *
  * @param start: start position of the vector
  * @param end: end position of the vector
  */
Vector create_vector(Position start, Position end);

/**
  * This function returns the NULL Vector.
  * So (start=(0,0), end=(0,0).
  */
const Vector* null_v(); 
/**
  *
  * This function returns the gravity Vector pointer.
  * There is only one instance of this Vector.
  */
const Vector* grav();

/**
  * This function adds two vectors.
  * 
  * @param a: first vector
  * @param b: second vector 
  */
Vector v_add(Vector a, Vector b);

/**
  * This function apply a Vector to a Position.
  *
  * @param a: the position to apply the Vector
  * @param b: the Vector
  */
Position p_v_apply(Position a, Vector b);

/**
  * This function multiplies a Vector by a scalar.
  *
  * @param v: the Vector to multiply
  * @param scalar: the scalar to apply
  */
Vector v_mult(Vector v, double scalar);

/**
  * This function divides a Vector by a scalar.
  *
  * @param v: the Vector to divide
  * @param scalar: the scalar to apply
  */
Vector v_div(Vector v, float scalar);

/**
  * This function computes the dot product
  * between two Vectors.
  * 
  * @param a: first Vector
  * @param b: second Vector
  */
double dot(Vector a, Vector b);

/**
  * This function computes the euclidian
  * norm of a Vector (√x²+y²).
  *
  * @param v: the Vector to get the norm
  */
double norm(Vector v);

#endif
