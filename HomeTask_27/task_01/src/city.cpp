#include "city.h"
#include "tree.h"

City::City() : city(5) {
}

City::~City() {
}

void City::genTree() {
  for (size_t i {0}; i < city.size(); i++) {
    std::cout << "tree# " << i << std::endl;
    city[i].genBranche();
  }
}

void City::find(std::string &name) {
  for (size_t i {0}; i < city.size(); i++) {
    city[i].find(name);
  }
}
