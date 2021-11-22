#pragma once
#include "border.h"

class Square : public Border {
public:
  Square();
  Square(double);
  ~Square();
  double getArea();
};
