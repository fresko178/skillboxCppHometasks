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
string getResult(string);

int main() {
  array<string, SIZE> field;
  cout << "Задание 5. Анализ результатов игры в крестики-нолики" << endl << endl;
  cout << "Введите игровое поле: " << endl;
  cin >> field[0];
  cin >> field[1];
  cin >> field[2];
  cout << endl;

  cout << "result = " << getResult(checkField(field)) << endl << endl;

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

string getResult(string str) {
  int countX = 0; // число победивших комбинаций X
  int countO = 0; // число победивших комбинаций O
  if (str == INCORRECT) {
      return INCORRECT; // некорректный ввод игрового поля
  }
  for (size_t pos = 0; pos <= str.length() - 3; pos += 3) {
    if (str.substr(pos, 3) == "XXX") {
      countX++;
    } else if (str.substr(pos, 3) == "OOO") {
      countO++;
    }
  }
  if (countX > 1 || countO > 1) {
    return INCORRECT; // некорректный ввод игрового поля
  } else if (countX == 1 && countO == 0) {
    str = PETYA_XWON;
  } else if (countX == 0 && countO == 1) {
    str = VANYA_OWON;
  } else {
    str = NOBODY;
  }

  return str;
}

