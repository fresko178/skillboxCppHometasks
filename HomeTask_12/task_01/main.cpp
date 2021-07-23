#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int SIZE {10};

int main() {
  string surnames[SIZE];
  cout << "Задача 1. Многоквартирный дом" << endl << endl;
  cout << "Введите 10 фамилий жильцов: " << endl;

  for (int i = 0; i < SIZE; i++) {
    std::getline(cin, *(surnames + i));
  }

  cout << endl << "Введите 3 номера квартир (1 - 10): " << endl;
  int apartment = 0;
  for (int i = 0; i < 3; i++) {
    cout << i + 1 << " номер квартиры: ";
    cin >> apartment;
    if (apartment < 1 || apartment > SIZE) {
      i--;
      cout << "введён некорректный номер квартиры, повторите ввод" << endl;
    } else {
      cout << "в квартире номер " << apartment << " проживает "
           << *(surnames + apartment - 1) << endl;
    }
  }

  cout << endl;

  return 0;
}

