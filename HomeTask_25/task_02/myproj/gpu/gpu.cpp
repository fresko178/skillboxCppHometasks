#include <iostream>
#include "gpu.h"
#include "ram.h"

void display(int numbers[]) {
  for (int i {0}; i < 8; i++) {
    std::cout << numbers[i] << std::endl;
  }
}

