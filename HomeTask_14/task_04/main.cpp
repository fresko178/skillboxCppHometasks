#include <iostream>

using std::cout;
using std::cin;
using std::endl;

constexpr int SIZE {4};

void print(int (*)[SIZE]);
bool equal(int (*)[SIZE], int (*)[SIZE]);
void setMatrix(int (*)[SIZE], char);

int main() {
  cout << "Задача 4. Равенство матриц" << endl << endl;
  int matrix1[SIZE][SIZE];
  int matrix2[SIZE][SIZE];
  setMatrix(matrix1, '1');
  setMatrix(matrix2, '2');
  cout << "матрица 1:" << endl;
  print(matrix1);
  cout << endl << "матрица 2:" << endl;
  print(matrix2);

  if (equal(matrix1, matrix2)) { cout << endl<< "матрицы равны" << endl; }
  else { cout << endl <<"матрицы НЕ равны" << endl; }
  cout << endl << endl;

  return 0;
}

void print(int (*arr)[SIZE]) {
  for(int row = 0; row < SIZE; row++) {
    for(int col = 0; col < SIZE; col++) {
      cout << *(*(arr + row) + col) << " ";
    }
    cout << endl;
  }
}

bool equal(int (*matrix1)[SIZE], int (*matrix2)[SIZE]) {
  for (int row = 0; row < SIZE; row++) {
    for(int col = 0; col < SIZE; col++) {
      if (*(*(matrix1 + row) + col) != *(*(matrix2 + row) + col)) { return false; }
    }
  }
  return true;
}

void setMatrix(int (*matrix)[SIZE], char ch) {
  cout << "Введите значения матрицы " << ch << endl;
  for(int row = 0; row < SIZE; row++) {
    for(int col = 0; col < SIZE; col++) {
      cin >> *(*(matrix + row) + col);
    }
    cout << endl;
  }
}

