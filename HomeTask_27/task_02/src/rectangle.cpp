#include "rectangle.h"

Rectangle::Rectangle(double width, double hight) {
  setData(width);
  this->height = hight;
}

Rectangle::~Rectangle() {
}

double Rectangle::getArea() {
  return getData() * height;
}

Frame Rectangle::getFrame() {
  Frame frame;
// координаты начала описывающего прямоугольника
  frame.coord.x = getCoord().x - (getData() / 2.0) - 1.0;
  frame.coord.y = getCoord().y + (height / 2.0) + 1.0;
// размеры описывающего прямоугольника
  frame.width = getData() + 1.0;
  frame.height = height + 1.0;
  return frame;
}
