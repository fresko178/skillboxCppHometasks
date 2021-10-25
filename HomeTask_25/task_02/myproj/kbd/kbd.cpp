#include <iostream>
#include "kbd.h"
#include "ram.h"

void input(int numbers[]) {
  for (int i {0}; i < 8; i++) {
    std::cout << "Введите число " << i + 1 << ": ";
    std::cin >> numbers[i];
  }
}

