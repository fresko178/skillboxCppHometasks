#include "border.h"

Border::Border() {
}

Border::~Border() {
}

void Border::setCoord(const double x, const double y) {
  coord = {x, y};
}

Coord Border::getCoord() const {
  return coord;
}

void Border::setColor(Color c) {
  color = c;
}

Color Border::getColor() const {
  return color;
}

void Border::setData(const double d) {
  data = d;
}

double Border::getData() const {
  return data;
}

Frame Border::getFrame() {
// координаты начала описывающего прямоугольника
  frame.coord.x = coord.x - (data / 2.0) - 1;
  frame.coord.y = coord.y + (data / 2.0) + 1;
// размеры описывающего прямоугольника
  frame.width = data + 1.0;
  frame.height = data + 1.0;
  return frame;
}
