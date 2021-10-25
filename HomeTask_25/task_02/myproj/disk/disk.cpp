#include <fstream>
#include "disk.h"
#include "ram.h"

/// сохраняет в файл 8 чисел
void save(int numbers[]) {
  std::ofstream file("save.txt");
  if (file.is_open()) {
    for (int i {0}; i < 8; i++) {
      file << numbers[i] << std::endl;
    }
  }
  file.close();
}

/// загружает из файла 8 чисел
void load(int numbers[]) {
  std::ifstream file("save.txt");
  if (file.is_open()) {
    for (int i {0}; i < 8; i++) {
      file >> numbers[i];
    }
  }
  file.close();
}

