#ifndef FUNCTION_H
#define FUNCTION_H
#include <cmath>

namespace tk
{
  double radians(double degree)
  {
    return ((2 * M_PI) * degree) / 360;
  }
  double degree(double radians)
  {
    return (360 * radians) / (2*M_PI);
  }

}

#endif
