#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

constexpr int length {5};
constexpr int width  {5};
constexpr int height {10};

void setMap(vector<vector<vector<bool>>> &);
size_t getSize(size_t, size_t);
void showSlice(vector<vector<vector<bool>>> &, size_t);

int main() {
  cout << "Задача 8. Почти-Майнкрафт" << endl;
  vector<vector<vector<bool>>> map(length, vector<vector<bool>>(width, vector<bool>(height, false)));
  setMap(map);
  int level = -1;
  while (-1 == level) {
    cout << "Введите номер уровня среза (0-9): ";
    cin >> level;
    if (level < 0 || level > height - 1) {
      level = -1;
      cout << "[ERROR] Введён несуществующий уровень, повторите попытку" << endl;
    }
  }
  showSlice(map, static_cast<size_t>(level));

  cout << endl << endl;
  return 0;
}

void setMap(vector<vector<vector<bool>>> & map) {
  for (size_t a = 0; a < length; a++) {
    for (size_t b = 0; b < width; b++) {
      size_t size = getSize(a, b);
      for (size_t c = 0; c < size; c++) {
        map[a][b][c] = true;
      }
    }
    cout << endl;
  }
}

size_t getSize(size_t a, size_t b) {
  int size {-1};
  while (-1 == size) {
    cout << "Введите высоту блока [" << a << "][" << b << "] = ";
    cin >> size;
    if (size < 0 || size > height) {
      size = -1;
      cout << "[ERROR] Введено некорректное значение высоты блока" << endl;
    }
  }
  return static_cast<size_t>(size);
}

void showSlice(vector<vector<vector<bool>>> &map, size_t level) {
  for (size_t a = 0; a < length; a++) {
    for (size_t b = 0; b < width; b++) {
      cout << map[a][b][level];
    }
    cout << endl;
  }
}

