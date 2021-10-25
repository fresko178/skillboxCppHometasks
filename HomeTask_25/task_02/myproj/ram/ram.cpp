#include "ram.h"
#include "kbd.h"
#include "gpu.h"

int numbers[8] {0, 0, 0, 0, 0, 0, 0, 0};

void write() {
  input(numbers);
}

int* read(void) {
  return numbers;
}

