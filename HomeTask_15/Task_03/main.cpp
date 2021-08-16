#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using Vec = vector<int>;

void enter(Vec &, int &x);

int main() {
  cout << "Задача 3" << endl;
  cout << "(-1 вывод, -2 выход)" << endl;

  Vec vec;
  int x {0}; // вводимое значение
  while (x != -2) {
    enter(vec, x);
    if (x == -1 && vec.size() > 4) { // пользователь хочет вывести результат
      std::sort(vec.begin(), vec.end()); // сортируем
      cout << "вывод: " << vec[4] << " (отсортированный массив: ";
      for (int i : vec) {
        cout << i << " ";
      }
      cout << ")" << endl;
      x = 0;
    } else if (x != -2) { x = 0; } // если условие выше не выполняется, то ввод будет игнорироваться поэтому зануляем
  }
  cout << endl << endl;

  return 0;
}

void enter(Vec &vec, int &x) { // запоминаем введённые значения
  cout << "Ввод: ";
  while(x != -1 && x != -2) {
    cin >> x;
    if (x != -1 && x != -2) { vec.push_back(x); }
  }
}

