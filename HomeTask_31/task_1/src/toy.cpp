#include "toy.h"

Toy::Toy(string str) : name(str) {
}

Toy::Toy() : name("SomeToy") {
}

Toy::~Toy() {
}

string Toy::getName() const {
  return name;
}
