#include "cpu.h"
#include "ram.h"

int computer(int numbers[]) {
  int sum {0};
  for (int i {0}; i < 8; i++) {
    sum += numbers[i];
  }
  return sum;
}

