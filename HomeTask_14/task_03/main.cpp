#include <iostream>

using std::cout;
using std::endl;

constexpr int SIZE {5};

void print(int(*)[SIZE]);

int main() {
  cout << "Задача 3. Проход змейкой" << endl << endl;
  int arr[SIZE][SIZE];
  int num = 0; // значение заполняющее массив
  int buf = 0; // row index buffer (0 go -->, 4 go <--)
  int res = 0; // рассчитанный индекс строки
  for (int col = 0; col < SIZE; col++) {
    for(int row = 0; row < SIZE; row++) {
      res = std::abs(buf - row); // calculation index row
      *(*(arr + col) + res) = num++; // перекручиваем индексы и заполняем строку
    }
    buf = res; // save index row
  }
  print(arr);
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


