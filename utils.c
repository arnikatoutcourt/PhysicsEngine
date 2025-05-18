#include "utils.h"
#include <float.h>

bool find_intersection(Vector a, Vector b, Position* intersection) {
  // Points of a Vector
  double x1 = a.start.x;
  double y1 = a.start.y;
  double x2 = a.end.x;
  double y2 = a.end.y;
  // Points of b Vector
  double x3 = b.start.x;
  double y3 = b.start.y;
  double x4 = b.end.x;
  double y4 = b.end.y;
  // Compute determinant
  double denom = (x2-x1) * (y3-y4) - (y2-y1) * (x3-x4);
  // Parallel or colinear
  if(denom > -DBL_EPSILON && denom < DBL_EPSILON) {
    return false;
  }
  // Compute intersection
  double t_num = (x3-x1) * (y3-y4) - (y3-y1) * (x3-x4);
  double u_num = (x2-x1) * (y3-y1) - (y2-y1) * (x3-x1);
  
  double t = t_num / denom;
  double u = u_num / denom;
  // check if intersection point is on the two segments
  // If t=0, intersection point is a.start 
  // If t=1, intersection point is a.end (same for u & b)
  if (t >= (0.0-DBL_EPSILON) && t <= (1.0+DBL_EPSILON) &&
      u >= (0.0-DBL_EPSILON) && u <= (1.0+DBL_EPSILON)) {
    intersection->x = x1 + t*(x2-x1);
    intersection->y = y1 + t*(y2-y1);
    return true;
  }
  return false;
}


