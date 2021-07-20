#include <iostream>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;

const int SIZE {3};
const string INCORRECT  = "Incorrect";
const string PETYA_XWON = "Petya won";
const string VANYA_OWON = "Vanya won";
const string NOBODY     = "Nobody";

string checkField(array<string, SIZE>);
string getResult(string, int, int, int);

int main() {
  array<string, SIZE> field;
  cout << "Задание 5. Анализ результатов игры в крестики-нолики" << endl << endl;
  cout << "Введите игровое поле: " << endl;
  cin >> field[0];
  cin >> field[1];
  cin >> field[2];
  cout << endl;

  int countX = 0;    // количество X
  int countO = 0;    // количество O
  int countDot = 0;  // количество .
  string str = field[0] + field[1] + field[2];
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == 'X') { countX++; }
    else if (str[i] == 'O') { countO++; }
    else { countDot++; }
  }
  cout << getResult(checkField(field), countX, countO, countDot) << endl << endl;

  return 0;
}

// если проверка поля на корректность ввода прошла удачно,
// то возвращаем строку иначе "Incorrect"
string checkField(array<string, SIZE> field) {
  string str = ""; // создаём строку из всех кандидатов выйгрышных вариантов
  for (size_t i = 0; i < SIZE; i++) {
    if (field[i].length() != 3) {
      return INCORRECT; // неверный размер поля
    } else {
        str += field[i]; // клеим горизонтальные строчки
    }
    for (size_t j = 0; j < SIZE; j++) {
      str += field[j][i]; // клеим вертикальные строчки
    }
  }
  for (size_t i = 0; i < SIZE; i++) {               // X
    str += field[i][i]; // клеим диагональную строчку   X
  }                                                 //   X
  for (size_t i = 0; i < SIZE; i++) {                       //    X
    str += field[i][SIZE - i - 1];// клеим диагональную строчку  X
  }                                                         //  X
  if (str.find_first_not_of("OX.") != string::npos) {
      return  INCORRECT;  // в поле присутствуют недопустимые символы
  }

  return str;
}

string getResult(string str, int countX, int countO, int countDot) {
  int countWinX = 0; // число победивших комбинаций X
  int countWinO = 0; // число победивших комбинаций O

  if (str == INCORRECT) {
      return INCORRECT + "  некорректный ввод игрового поля ";
  }
  for (size_t pos = 0; pos <= str.length() - 3; pos += 3) {
    if (str.substr(pos, 3) == "XXX") {
      countWinX++;
    } else if (str.substr(pos, 3) == "OOO") {
      countWinO++;
    }
  }

  if (countWinX > 1 || countWinO > 1 || (countWinX == 1 && countWinO == 1)) {
    return INCORRECT + "  некорректный ввод игрового поля ";
  } else if (countO > countX) {
    str =  INCORRECT + "  ноликов в конце игры не может быть больше ";
  } else if (countWinX == 0 && countWinO == 1 && (countO > countX)) {
    str =  INCORRECT + "  нолики победили, но при этом их не может быть больше";
  } else if (countWinX == 0 && countWinO == 0 && countDot != 0) {
    str = NOBODY + "  потому что они не доиграли";
  } else if (countWinX == 0 && countWinO == 0 && countDot == 0) {
    str = NOBODY + "  потому что это ничья";
  } else if (countWinX == 0 && countWinO == 1 && (countO < countX)) {
    str =  INCORRECT + "  нолики победили, но при этом крестиков не может быть больше";
  } else if (countWinX == 1 && countWinO == 0 && (countO == countX)) {
    str =  INCORRECT + "  крестики победили, но при этом ноликов не может быть столькоже";
  } else if (countWinX == 1 && countWinO == 0 && (countO < countX)) {
    str = PETYA_XWON;
  } else if (countWinX == 0 && countWinO == 1 && (countO == countX)) {
    str = VANYA_OWON;
  } else {
    str = "ERROR: Something went wrong ";
  }

  return str;
}

