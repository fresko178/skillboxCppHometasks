#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  cout << "Задача 2. Ряд чисел" << endl << endl;
  int numbers [] {1, 3, 2, 4, 5, 7, 10, 13, 9, 6, 11, 12, 8 ,13, 14};
  for (int i = 0; i < 15; i++) { // просто выводим для наглядности
    cout << "  " << numbers[i];
  }                  
  cout << endl;
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      if (i != j && (numbers[i] == numbers[j])) {
        cout << "повторяющееся число: " << numbers[i] << endl;
        return 0; // валим, лишнюю работу не делаем
      }
    }
  }

  cout << endl;

  return 0;
}

