#include <iostream>

using std::cout;
using std::endl;

int recursion(int purpose);

int main() {
  cout << "Задача 2." << endl << endl;
  cout << "Введите номер ступеньки: ";
  int purpose;
  std::cin >> purpose;
  cout << "Кол. способов = " << recursion(purpose) << endl;

  cout << endl << endl;
  return 0;
}

int recursion(int purpose) {
  if (purpose < 0) { return 0; }
  if (purpose == 0) { return 1; }

  return recursion(purpose - 3) + recursion(purpose - 2) + recursion(purpose - 1);
}

