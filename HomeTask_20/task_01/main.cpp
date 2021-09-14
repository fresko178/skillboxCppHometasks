#include <iostream>
#include <fstream>
#include <string_view>
#include <algorithm>
#include <array>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::string_view;
using Arr = std::array<string, 3>;

Arr getSubStrings(const string_view &);
bool checkName(const string_view &);
bool checkDate(const string &);
bool getDate(string &);
bool getMoney(string &);

int main() {
  cout << "Задание 1. Реализация записи в ведомость учёта" << endl;
  std::ofstream file("statement.txt", std::ios::app);
  string name {""};
  string date {""};
  string money {""};
  string str {""};
  char ch {'y'};
  if (file.is_open()) {
    while (ch == 'y' || ch == 'Y') { // пользователь продолжает заполнять ведомость
      cout << endl << "Введите имя: ";
      cin >> name;
      cout << "Введите фамилию: ";
      cin >> str;
      name += " " + str;
      if (!checkName(name)) {
        cout << "[ОШИБКА] Введено некорректное имя" << endl;
        continue;
      }
      while (!getDate(date));
      while (!getMoney(money));
      file << name << " " << date << " " << money << endl;
      cout << endl << "Хотите продолжить? (Y/N): ";
      cin >> ch;
    }
    file.close();
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для чтения" << endl;
    exit(EXIT_FAILURE);
  }
  return 0;
}

Arr getSubStrings(const string_view &str) {
  Arr subStrings;
  for (size_t i = 0, j = 0; i < str.length(); i++) {
    if(str[i] == '.') { j++; }
    else { subStrings[j] += str[i]; }
  }
  return subStrings;
}

bool checkName(const string_view &str) {
  for(size_t i {0}; i < str.length(); i++) {
    if (!std::isalpha(str[i])) { // в имени не буква
      if (str[i] != ' ') { return false; } // и не разделитель пробельный
    }
  }
  return true;
}

bool checkDate(const string &str) {
  if (str.length() < 6)  { // длина строки с датой не может быть < 6 символов (d.m.yy)
    return false;
  }
  if (std::count(str.begin(), str.end(), '.') != 2) {
    return false; // недопустимое кол. '.'
  }
  if (str.find("..") != string::npos) {
    return false; // недопустимое кол. точек идущих подрят
  }
  if (*str.begin() == '.' || *str.end() == '.') {
    return false; // недопустимый первый или последний символ
  }
  Arr subStrings = getSubStrings(str);
  for (size_t i = 0; i < 3; i++) {
    if (subStrings[i].find_first_not_of("1234567890") != string::npos) {
      return false; // в строке присутствуют недопустимые символы
    } else {
      int num = std::stoi(subStrings[i], nullptr, 10);
      if (i == 0 && num > 31) { // число месяца
        return false; // некорректное значение
      } else if (i == 1 && num > 12) { // кол. месяцев
        return false; // некорректное значение
      } // год теоритически может быть любым, хоть 01 хоть 9000000
    }
  }
  return true;
}

bool getDate(string &date) {
  cout << "Введит дату (dd.mm.yy): ";
  cin >> date;
  if (!checkDate(date)) {
    cout << "[ОШИБКА] Введена некорректная дата" << endl;
    return false;
  }
  return true;
}

bool getMoney(string &money) {
  cout << "Введит сумму зачисления: ";
  cin >> money;
  if (money.find_first_not_of("1234567890") != string::npos) {
    cout << "[ОШИБКА] Введена некорректная сумма зачисления" << endl;
    return false; // в строке присутствуют недопустимые символы
  }
  return true;
}

