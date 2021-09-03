#include <iostream>

using std::cout;
using std::endl;

int recursion(int *, int, int, int, int &);

int main() {
  cout << "Задача 2." << endl << endl;
  cout << "Введите номер ступеньки: ";
  int purpose;
  std::cin >> purpose;
  int arr[purpose];    // массив который хранит комбинации ступенек
  int count {0}; // кол. способов
  count = recursion(arr, purpose, 0, 1, count);
  cout << "Кол. способов = " << count;

  cout << endl << endl;
  return 0;
}

// arr - массив который хранит тек. комбинации ступенек
// purpose – номер ступеньки
// pos - позиция в массиве
// elem – элемент массива
// count - кол. способов
int recursion(int *arr, int purpose, int pos, int elem, int &count) {
  for (auto i = elem ; i <= purpose - 1; i++) {
    arr[pos] = i;
    recursion(arr, purpose - i, pos + 1, i, count);
  }
  count++;
  cout << count << "]  (";
  for (int i = 0 ; i < pos; i++) {
    cout << arr[i] << " ";
  }
  cout << purpose << ") " << endl;

  return count;
}

