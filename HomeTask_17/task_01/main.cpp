#include <iostream>

using std::cout;
using std::endl;

void swap(int *, int *);

int main() {
  cout << "Задача 1." << endl << endl;
  int a {10};
  int b {20};

  cout << "a = " << a << endl;
  cout << "b = " << b << endl << endl;
  swap(&a, &b);
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  cout << endl << endl;
  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

