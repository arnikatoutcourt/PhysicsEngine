#include "vector.h"

Vector create_vector(Position start, Position end) {
  Vector v;
  v.start = start;
  v.end = end;
  v.dx = v.end.x - v.start.x;
  v.dy = v.end.y - v.start.y;
  return v;
}

const Vector* null_v() {
  static Vector null_instance;
  static bool is_init = false;
  if(!is_init) {
    Position start = {0.0, 0.0};
    Position end = {0.0, 0.0};
    null_instance = create_vector(start, end);
    is_init = true;
  }
  return &null_instance;
}

const Vector* grav() {
  static Vector g_instance;
  static bool is_init = false;
  if(!is_init) {
    Position start = {0.0, 0.0};
    Position end = {0.0, -9.81};
    g_instance = create_vector(start, end);
    is_init = true;
  }
  return &g_instance;
}

Vector v_add(Vector a, Vector b) {
  return create_vector(a.start, b.end);
}

Position p_v_apply(Position a, Vector b) {
  Position npos;
  npos.x = a.x + b.dx;
  npos.y = a.y + b.dy;
  return npos;
}

Vector v_mult(Vector v, double scalar) {
  Position nend;
  nend.x = v.start.x + v.dx * scalar;
  nend.y = v.start.y + v.dy * scalar;
  return create_vector(v.start, nend);
}

Vector v_div(Vector v, float scalar) {
  Position nend;
  nend.x = v.start.x + v.dx / scalar;
  nend.y = v.start.y + v.dy / scalar;
  return create_vector(v.start, nend);
}

double dot(Vector a, Vector b) { 
  return (a.dx * b.dx) + (a.dy * b.dy);
}

double norm(Vector v){
  return sqrt(pow(v.dx, 2) + pow(v.dy, 2));
}


