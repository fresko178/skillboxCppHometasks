#include <iostream>

using std::cout;
using std::cin;
using std::endl;

constexpr int SIZE {3};
void printField(char(*)[SIZE]);
bool isCorrect(int, int, char(*)[SIZE]);
bool playerTurn(char , char(*)[SIZE]);
bool isRun(char(*)[SIZE]);

int main() {
  cout << "Задача 2. Крестики-нолики" << endl << endl;
  cout << "Координаты как индексация в массиве" << endl << endl;
  char field[][SIZE] {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  bool run = true; // признак работающей программы
  while (run) {
    while (!playerTurn('X', field)); // игрок X вводит координаты
    printField(field);  // печатаем текущее состояние поля
    if (!isRun(field)) { // выясняем победил ли игрок X
      run = false;      // победитель выявлен, заканчиваем игру
    } else {
      while (!playerTurn('O', field)); // игрок O вводит координаты
      printField(field);  // печатаем текущее состояние поля
      run = isRun(field); // тогда возможно победил игрок O или никто или играем дальше
    }
  }
  cout << endl << endl;

  return 0;
}

void printField(char (*p)[SIZE]) {
  cout << "игровое поле: " << endl;
  for(int row = 0; row < SIZE; row++) {
      cout << " ";
    for(int col = 0; col < SIZE; col++) {
      cout << *(*(p + row) + col);
      if (col < 2) { cout << "|"; }
    }
    if (row < 2) { cout << endl << " -----" << endl; }
    else { cout << endl << endl; }
  }
}

// проверяет вводимые координаты пользователя на корректность
// и возможность хода в клетку по координатам
bool isCorrect(int row, int col, char (*field)[SIZE]) {
  if (row < 0 || row > 2 || col < 0 || col > 2) {
    return false; // wrong coordinates
  } else if (*(*(field + row) + col) != ' ') {
    return false; // access denied
  }
  return true;
}

// заполняет игровое поле
// ch - символ хода 'X' или 'O'
// возвращает true если пользователь совершил ход удачно
//            false если пользователь не смог совершить ход
bool playerTurn(char ch, char(*field)[SIZE]) {
    int row = 0, col = 0;
    cout << "Введите координаты для хода игрока '" << ch <<"': " << endl;
    cin >> row >> col;
    if (isCorrect(row, col, field)) {
      *(*(field + row) + col) = ch;
      return true;
    } else {
      row = col = 0;
      cout << "[ERROR]: Введены некорректные координаты, повторите ввод" << endl << endl;
    }
  return false;
}

// определяет результат игры, её продолжение или окончание
// возвращает true если игра продолжается
//            false игра окончена
bool isRun(char(*field)[SIZE]) {
  int countGX = 0; // кол. крестиков по горизонтали
  int countGO = 0; // кол. ноликов по горизонтали
  int countVX = 0; // кол. крестиков по вертикали
  int countVO = 0; // кол. ноликов по вертикали
  int countSpace = 0;
  for(int row = 0; row < SIZE; row++) {
    for(int col = 0; col < SIZE; col++) {
      if (*(*(field + row) + col) == 'X') { countGX++; }
      if (*(*(field + row) + col) == 'O') { countGO++; }
      if (*(*(field + col) + row) == 'X') { countVX++; }
      if (*(*(field + col) + row) == 'O') { countVO++; }
      if (*(*(field + row) + col) == ' ') { countSpace++; }
    }
    if (3 == countGX || 3 == countVX) {
      cout << endl << "Победил игрок 'X'" << endl;
      return false;
    } else if (3 == countGO || 3 == countVO) {
      cout << endl << "Победил игрок 'O'" << endl;
      return false;
    }
    countGX = countVX = countGO = countVO = 0;
  }
  if (0 == countSpace) { // gameover
    cout << endl << "Ничья" << endl;
    return false;
  }
  return true;
}

