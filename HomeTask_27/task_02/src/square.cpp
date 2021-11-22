#include "square.h"

Square::Square() {
}

Square::Square(double len) {
  setData(len);
}

Square::~Square() {
}

double Square::getArea() {
  return getData() * getData();
}
