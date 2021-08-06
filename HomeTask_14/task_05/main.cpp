#include <iostream>

using std::cout;
using std::cin;
using std::endl;

constexpr int SIZE {4};

void print(float (*)[SIZE]);
void setMatrix(float (*)[SIZE]);

int main() {
  cout << "Задача 5. Диагональная матрица" << endl << endl;
  float matrix[SIZE][SIZE];

  setMatrix(matrix);
  cout << endl << "матрица :" << endl;
  print(matrix);
  // Note: Не уверн правильно ли я понял задание
  cout << endl << "диагональная матрица :" << endl;
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      if (row != col) { *(*(matrix + row) + col) = 0; }
    }
  }
  print(matrix);

  cout << endl << endl;

  return 0;
}

void print(float (*arr)[SIZE]) {
  for(int row = 0; row < SIZE; row++) {
    for(int col = 0; col < SIZE; col++) {
      cout << *(*(arr + row) + col) << " ";
    }
    cout << endl;
  }
}

void setMatrix(float (*matrix)[SIZE]) {
  cout << "Введите значения матрицы " << endl;
  for(int row = 0; row < SIZE; row++) {
    for(int col = 0; col < SIZE; col++) {
      cin >> *(*(matrix + row) + col);
    }
    cout << endl;
  }
}

