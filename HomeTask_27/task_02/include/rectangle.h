#pragma once
#include "border.h"

class Rectangle : public Border {
  double height;
public:
  Rectangle(double, double);
  ~Rectangle();
  double getArea();
  Frame getFrame();
};
