#include "triangle.h"
#include <cmath>

Triangle::Triangle(double len) {
  setData(len);
}

Triangle::~Triangle() {
}

double Triangle::getArea() {
  return (sqrt(3) * (getData() * getData())) / 4.0;
}
