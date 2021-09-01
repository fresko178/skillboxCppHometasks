#include <iostream>

constexpr int SIZE {10};

using std::cout;
using std::endl;

void reverse(int arr[]);
void print(int arr[]);

int main() {
  cout << "Задача 2." << endl << endl;
  int arr[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  print(arr);
  reverse(arr);
  cout << endl;
  print(arr);

  cout << endl << endl;
  return 0;
}

void reverse(int arr[]) {
  int temp {0};
  for (int i {0}; i < SIZE / 2; i++) { // меняем значения от начала с значением от конца
    temp = arr[i];
    arr[i] = arr[SIZE - i - 1];
    arr[SIZE - i - 1] = temp;
  }
}

void print(int arr[]) {
  for (int i = 0; i < SIZE; i++) {
    cout << " " << arr[i];
  }
}

