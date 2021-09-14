#include <iostream>
#include <fstream>
#include <ctime>

using std::endl;
using std::cout;
using std::cin;

int main() {
  cout << "Задание 2. Реализация рисования случайных картин" << endl;
  std::ofstream file("pic.txt");
  if (file.is_open()) {
    int length {0};
    int width {0};
    cout << endl << "Введите длину картины: ";
    cin >> length;
    cout << "Введите ширину картины: ";
    cin >> width;
    file << endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int row {0}; row < length; row++) {
      for (int col {0}; col < width; col++) {
        file << std::rand() % 2;
      }
      file << endl;
    }
    file.close();
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для чтения" << endl;
    exit(EXIT_FAILURE);
  }
  return 0;
}

