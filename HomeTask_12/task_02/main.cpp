#include <iostream>

using std::cout;
using std::cin;
using std::endl;

constexpr int magic {1561};

int main() {
  cout << "Задача 2. Ряд чисел" << endl << endl;
  int numbers [] {114, 111, 106, 107, 118, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
  int sum {0};
  for (int i = 0; i < 15; i++) {
    sum += *(numbers + i); // сумма всех элементов
    cout << "  " << *(numbers + i);
  }
  cout << endl << endl << "повторяющееся число: " << sum - magic << endl << endl;

  return 0;
}

