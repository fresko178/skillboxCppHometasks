#include "circle.h"
#include <cmath>

Circle::Circle(double radius) {
  setData(radius);
}

Circle::~Circle() {
}

double Circle::getArea() {
  return M_PI * (getData() * getData());
}
