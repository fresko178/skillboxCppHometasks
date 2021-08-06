#include <iostream>

using std::cout;
using std::cin;
using std::endl;

constexpr int SIZE {12};

void setWrapper(bool(*)[SIZE]);
bool printWrapper(bool(*)[SIZE]);
int pop(bool(*)[SIZE],int, int, int, int);
bool checkCoordinates(int, int, int, int);

int main() {
  cout << "Задача 7. Пупырка" << endl;
  bool wrapper[SIZE][SIZE];
  setWrapper(wrapper); // инициализируем
  printWrapper(wrapper);
  bool run {true}; // признак продолжения деяния лопанья
  int row1 {0}, col1 {0}, row2 {0}, col2 {0}; // координаты
  while(run) {
    cout << "Введите координаты начала региона лопанья:" << endl;
    cin >> row1 >> col1;
    cout << "Введите координаты конца региона лопанья:" << endl;
    cin >> row2 >> col2;
    if (!checkCoordinates(row1, col1, row2, col2)) {
      cout << "[ERROR] Введены некорректные координаты" << endl << endl;
      continue;
    } // повторить ввод координат
    for (int i = pop(wrapper, row1, col1, row2, col2); i > 0; i--) {
      cout << "Pop!  ";
    }
    if(!printWrapper(wrapper)) {run = false;} // все пузыри лопнуты, прекращаем работу
  }

  cout << endl << endl;
  return 0;
}

void setWrapper(bool (*wrapper)[SIZE]) {
  for(int row {0}; row < SIZE; row++) {
    for(int col {0}; col < SIZE; col++) {
      *(*(wrapper + row) + col) = true;
    }
  }
}

bool printWrapper(bool (*wrapper)[SIZE]) {
  cout << endl;
  bool bubble {false}; // признак отсутствия целых пузырей
  for(int row {0}; row < SIZE; row++) {
    for(int col {0}; col < SIZE; col++) {
      if (*(*(wrapper + row) + col)) {
        cout << " O";
        bubble = true; // нашёлся целый пузырёк
      } else {
        cout << " X";
      }
    }
    cout << endl;
  }
  cout << endl;
  return bubble;
}

int pop(bool(*wrapper)[SIZE], int row1, int col1, int row2, int col2) {
  if (row1 > row2) { row1 ^= row2 ^= row1 ^= row2; } // если первая координата старше второй
  if (col1 > col2) { col1 ^= col2 ^= col1 ^= col2; }
  int countPop {0}; // число лопающихся пузырьков
  for (int i = row1; i <= row2; i++) {
    for (int j = col1; j <= col2; j++) {
      if (*(*(wrapper + i) + j) == true) {
        *(*(wrapper + i) + j) = false;
        countPop++;
      }
    }
  }
  return countPop;
}

bool checkCoordinates(int row1, int col1, int row2, int col2) {
  if ( row1 < 0 || row1 > SIZE - 1
    || row2 < 0 || row2 > SIZE - 1
    || col1 < 0 || col1 > SIZE - 1
    || col2 < 0 || col2 > SIZE - 1) {
    return false;
  }
  return true;
}

