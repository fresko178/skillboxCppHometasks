#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

constexpr int SIZE {20};
void printDB(const std::vector<int> &, size_t);

int main() {
  cout << "Задача 3. " << endl;
  cout << "Введите значения в базу данных (-1 выход) " << endl << endl;

  std::vector<int> vecDB(SIZE);
  int data = 0;
  size_t i = 0;
  do { // кольцевая запись
    cin >> data;
    if (data != -1) {
      if (i == SIZE) { i = 0; }
      vecDB[i] = data;
      i++;
    }
  } while(data != -1);
  cout << "vector: ";
  cout << endl;
  printDB(vecDB, i);

  return 0;
}

// &vecDB - выводимый вектор
// index - самый старый элемент
void printDB(const std::vector<int> &vecDB, size_t index) {
  for (size_t j = index ; j < SIZE; j++) { // выводим начиная со старого элемента
    cout << vecDB[j] << " ";
  }
  for (size_t j = 0; j < index; j++) { // выводим всё до старого элемента
    cout << vecDB[j] << " ";
  }
  cout << endl;
}

