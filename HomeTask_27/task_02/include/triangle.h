#pragma once
#include "border.h"

class Triangle : public Border {
public:
  Triangle(double);
  ~Triangle();
  double getArea();
};
