#include <iostream>
#include <array>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;

const int SIZE {2};

bool checkNumber(string);
array<string, SIZE> getSubStrings(string, char);
void cutNULL(array<string, SIZE> *);

int main() {
  string number1 = "";
  string number2 = "";
  cout << "Задание 4. Сравнение длинных вещественных чисел" << endl << endl;
  cout << "Введите первое число: ";
  cin >> number1;
  cout << "Введите второе число: ";
  cin >> number2;
  cout << endl;

  if (checkNumber(number1) && checkNumber(number2)) {
    array<string, SIZE> real1 = getSubStrings(number1, '.');
    array<string, SIZE> real2 = getSubStrings(number2, '.');
    cutNULL(&real1);
    cutNULL(&real2);
    string res = real1[0] > real2[0] ? "More" : real1[0] == real2[0] ? "Equal" : "Less";
    if (res == "Equal") {
      res = real1[1] > real2[1] ? "More" : real1[1] == real2[1] ? "Equal" : "Less";
    }
    cout << "res = " << res << endl;
  } else {
    cout << "Введено некорректное значение " << endl;
  }

  return 0;
}

bool checkNumber(string number) {
  bool good = true;
  if (number.find_first_of("1234567890") == string::npos) {
    good = false; // число не содержит цифр
  }
  if (number.find_first_not_of("1234567890.-") != string::npos) {
    good = false; // в числе присутствуют недопустимые символы
  } else {
    int countDots = 0;
    for (size_t i = 0; i < number.length(); i++) {
      if (number.at(i) == '.') {
          countDots++;
      }
      if (i > 0 && number.at(i) == '-') {
        good = false; // знак минус может стоять только в начале
      }
    }

    if (countDots > 1) {
      good = false; // кол. точек не может быть больше одной
    }
  }

  return good;
}

array<string, SIZE> getSubStrings(string str, char ch) {
  array<string, SIZE> subStrings;
  size_t j = 0;
  for (size_t i = 0; i < str.length(); i++) {
    if(str[i] == ch) { j++; }
    else { subStrings[j] += str[i]; }
  }
  if (j == 0) { // дробной части нет
    subStrings[1] += '0';
  }

  return subStrings;
}

void cutNULL(array<string, SIZE> *number) {
  string s = "";
  for (size_t i = 0; i < (*number)[0].length() - 1; i++) {
    if ((*number)[0][i] == '0' && s == "") {
      ; // пропускаем '0', если он не единственный
    } else if ((*number)[0][i] == '0' && s == "-") {
      ; // пропускаем '0', если он не единственный
    } else {
      s += (*number)[0][i];
    }
  }
  s += (*number)[0][(*number)[0].length() - 1];
  (*number)[0] = s;

  s = "";
  for (size_t i = (*number)[1].length() - 1; i > 0; i--) {
    if ((*number)[1][i] == '0' && s == "") {
      ; // пропускаем '0', если он не единственный
    } else {
      s += (*number)[1][i];
    }
  }
  s += (*number)[1][0];
  std::reverse(s.begin(), s.end());
  (*number)[1] = s;
}

