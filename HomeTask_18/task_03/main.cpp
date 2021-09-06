#include <iostream>

using std::cout;
using std::endl;

int recursion(int *, int, int, int, int &, int len = 3);

int main() {
  cout << "Задача 2." << endl << endl;
  cout << "Введите номер ступеньки: ";
  int purpose;
  std::cin >> purpose;
  cout << "Введите длину прыжка: ";
  int len;
  std::cin >> len;

  int arr[purpose]; // массив который хранит комбинации ступенек
  int count {0}; // кол. способов
  cout << endl;
  count = recursion(arr, purpose, 0, 1, count, len);
  cout << "Кол. способов = " << count;

  cout << endl << endl;
  return 0;
}

// arr - массив который хранит тек. комбинации ступенек
// purpose – номер ступеньки до которой нужно допрыгать
// pos - позиция в массиве
// elem – элемент массива
// count - кол. способов
// len - максимальная длина прыжка
int recursion(int *arr, int purpose, int pos, int elem, int &count, int len) {
  for (auto i = elem ; i <= purpose - 1; i++) {
    if(i > len) { break; } // недопустимой длины прыжок
    arr[pos] = i;
    recursion(arr, purpose - i, pos + 1, i, count, len);
  }
  if (purpose <= len) { // допустимой длины последний прыжок
    count++; // кол. способов
    cout << count << "]  (";
    for (int i = 0 ; i < pos; i++) { // выводим комбинацию
      cout << arr[i] << " ";
    }
    cout << purpose << ") " << endl;
  }

  return count;
}

