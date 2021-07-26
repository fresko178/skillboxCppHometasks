#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
  cout << "Задача 2. Ряд чисел" << endl << endl;
  int numbers [] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 12, 13 ,14, 15};
  for (int i = 0; i < 15; i++) { // просто выводим для наглядности
    cout << "  " << numbers[i];
  }                  
  cout << endl << endl;
  for (int i = 0; i < 14; i++) {
    if (numbers[i] == numbers[i + 1]) {
      cout << "повторяющееся число: " << numbers[i] << endl;
      return 0; // лишнюю работу не делаем
    }
  }

  cout << endl;

  return 0;
}

