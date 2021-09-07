#include <iostream>

using std::cout;
using std::endl;

int recursion(int, int);

int main() {
  cout << "Задача 3." << endl << endl;
  cout << "Введите номер ступеньки: ";
  int purpose;
  std::cin >> purpose;
  cout << "Введите длину прыжка: ";
  int len;
  std::cin >> len;

  cout << "Кол. способов = " << recursion(purpose, len) << endl;

  cout << endl << endl;
  return 0;
}

int recursion(int purpose, int len) {
  if (purpose < 0) { return 0; }
  if (purpose == 0) { return 1; }

  int count {0};
  for (int i = len; i > 0; i--) {
    count += recursion(purpose - i, len);
  }

  return count;
}

