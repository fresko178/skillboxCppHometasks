#pragma once
#include "border.h"

class Circle : public Border {
public:
  Circle(double);
  ~Circle();
  double getArea();
};

