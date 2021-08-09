#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using Map = vector<vector<vector<bool>>>;

constexpr int LENGTH {5};
constexpr int WIDTH  {5};
constexpr int HEIGHT {10};

void setMap(Map &);
size_t getHeightBlock(size_t, size_t);
void showSlice(Map &, size_t);

int main() {
  cout << "Задача 8. Почти-Майнкрафт" << endl;
  Map map(LENGTH, vector<vector<bool>>(WIDTH, vector<bool>(HEIGHT, false))); // наш куб
  setMap(map); // устанавливаем в true ячейки столбцов, кроме ячеек превышающих значение высоты
  int level = -1;
  while (-1 == level) {
    cout << "Введите номер уровня среза (0-9): ";
    cin >> level;
    if (level < 0 || level > HEIGHT - 1) {
      level = -1;
      cout << "[ERROR] Введён несуществующий уровень, повторите попытку" << endl;
    }
  }
  showSlice(map, static_cast<size_t>(level));

  cout << endl << endl;
  return 0;
}

void setMap(Map &map) {
  for (size_t a = 0; a < LENGTH; a++) {
    for (size_t b = 0; b < WIDTH; b++) {
      size_t heightBlock = getHeightBlock(a, b); // получаем от пользователя значение высоты блока
      for (size_t c = 0; c < heightBlock; c++) {
        map[a][b][c] = true; // заполняем значениями ячейки блока до его высоты, всё что выше не трогаем
      }
    }
    cout << endl;
  }
}

size_t getHeightBlock(size_t a, size_t b) {
  size_t heightBlock {HEIGHT + 1};
  while (HEIGHT + 1 == heightBlock) {
    cout << "Введите высоту блока [" << a << "][" << b << "] = ";
    cin >> heightBlock;
    if (heightBlock > HEIGHT) {
      heightBlock = HEIGHT + 1;
      cout << "[ERROR] Введено некорректное значение высоты блока" << endl;
    }
  }
  return heightBlock;
}

void showSlice(Map &map, size_t level) {
  for (size_t a = 0; a < LENGTH; a++) {
    for (size_t b = 0; b < WIDTH; b++) {
      cout << map[a][b][level];
    }
    cout << endl;
  }
}
