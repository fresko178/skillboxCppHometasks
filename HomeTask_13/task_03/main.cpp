#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

constexpr int SIZE {20};
void printDB(const std::vector<int> &);

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
  printDB(vecDB);

  return 0;
}

void printDB(const std::vector<int> &vecDB) {
  for (auto &i : vecDB) {
    cout << i << " ";
  }
  cout << endl;
}

