#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using Vec = std::vector<int>;

void sortSelection(Vec &);
void printVec(Vec &);

int main() {
  cout << "Задача 4" << endl;

  Vec vec {-100,-50, -5, 1, 10, 15};
  cout << "до сортировки: ";
  printVec(vec);
  sortSelection(vec);
  cout << "после сортировки: ";
  printVec(vec);
  cout << endl << endl;

  return 0;
}

// Алгоритм такой: находим элем. с максимальным значением и минимальным, далее
// меняем местами последний с максимальным и первый элемент с минимальным,
// далее просмотр элементов начинается уже со второго и до предпоследнего, соответственно
// меняться местами будут уже предпоследний с максимальным и второй элемент с элементом у
// которого минимальное значение из просмотренных, ну и так далее
void sortSelection(Vec &vec) {
  size_t j {0};
  for (size_t i {0}; i < (vec.size() - 1) / 2; i++) { // пройдём половину т.к. остальное уже будет отсортировано
    j = i;
    size_t indexMax = j; // индекс элемента с максимальным значением
    size_t indexMin = j; // индекс элемента с минимальным значением
    while (j < vec.size() - i) {
      if (abs(vec[j]) > abs(vec[indexMax])) { indexMax = j; } // ищем индекс эелемента с макс. значением
      else if (abs(vec[j]) < abs(vec[indexMin])) { indexMin = j; } // ищем индекс эелемента с мин. значением
      j++;
    }
    int temp = vec[j - 1]; // запоминаем последний элем
    vec[j - 1] = vec[indexMax]; // теперь элем. с макс. значением в конце
    vec[indexMax] = temp;
    if (abs(vec[indexMin]) < abs(vec[indexMax])) {
      temp = vec[i];
      vec[i] = vec[indexMin]; // теперь элем. с мин. значением в начале
      vec[indexMin] = temp;
    }
  }
}

void printVec(Vec &vec) {
  for(int i : vec) {
    cout << " " << i;
  }
  cout << endl;
}

