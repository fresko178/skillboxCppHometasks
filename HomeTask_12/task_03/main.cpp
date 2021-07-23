#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int SIZE {15};

int main() {
  cout << "Задача 3. Сортировка" << endl << endl;
  cout << "Введите 15 дробных чисел" << endl;

  float numbers[SIZE];
  for (int i = 0; i < SIZE; i++) { // вводим
    cin >> numbers[i];
  }                  
  cout << endl;
  float tmp = 0.0f;
  for (int i = 0; i < SIZE - 1; i++) { // сортируем
    for (int j = 0; j < SIZE - 1; j++) {
      if (numbers[j] < numbers[j + 1]) {
        tmp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = tmp;
      }
    }
  }

  for (int i = 0; i < SIZE; i++) { // выводим
    cout << numbers[i] << endl;
  }                  

  cout << endl;

  return 0;
}

