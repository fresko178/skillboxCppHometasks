#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

constexpr int SIZE {4};

void printMatrix(float(*)[SIZE]);
void printVector(float*);
void setMatrix(float(*)[SIZE]);
void setVector(float*);
void calculate(float(*)[SIZE], float*, float*);

int main() {
  cout << "Задача 6. Умножение матрицы на вектор" << endl << endl;
  float matrix[SIZE][SIZE];
  float vec[SIZE];
  float res[SIZE];

  setMatrix(matrix);
  setVector(vec);
  cout << endl << "матрица:" << endl;
  printMatrix(matrix);
  cout << endl << "вектор:" << endl;
  printVector(vec);
  cout << endl << endl << "результат перемножения:" << endl;
  calculate(matrix, vec, res);
  printVector(res);

  cout << endl << endl;
  return 0;
}

void printMatrix(float (*matrix)[SIZE]) {
  for(int row = 0; row < SIZE; row++) {
    for(int col = 0; col < SIZE; col++) {
      cout << std::right << std::setw(4) << *(*(matrix + row) + col);
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

void printVector(float *vec) {
  for(int index = 0; index < SIZE; index++) {
    cout << std::right << std::setw(4) << *(vec + index);
  }
}

void setVector(float *vec) {
  cout << "Введите значения вектора " << endl;
  for(int index = 0; index < SIZE; index++) {
    cin >> *(vec + index);
  }
}

void calculate(float (*matrix)[SIZE], float *vec, float *res) {
  for (int row = 0; row < SIZE; row++) {
    *(res + row) = 0; // инициализируем (страхуемся)
    for (int col = 0; col < SIZE; col++) {
      *(res + row) +=  *(*(matrix + row) + col) * *(vec + col); // так и запутаться недолго
    }
  }
}

