#include <iostream>
#include <fstream>
#include <string_view>
#include <array>
#include <vector>
#include <algorithm>

struct reglist {
  std::string name;
  std::string surname;
  std::string date;
  std::string money;
};

using std::endl;
using std::cout;
using std::cin;
using std::string_view;
using std::string;
using Substrings = std::array<std::string, 3>;
using List = std::vector<reglist>;

constexpr string_view PATH {"reglist.txt"};

void saveFile(reglist &);
void readFile(List &);
bool getDate(string &);
bool getMoney(string &);
Substrings getSubStrings(const string_view &, const char &);
bool checkDate(const string_view &);

int main() {
  cout << "Задание 1. Реализация ведомости учёта" << endl << endl;

  std::string command {""};
  while (command != "add" && command != "read") {
    cout << endl << "Введите команду (add/read  добавить новую запись/прочитать все записи): ";
    cin >> command;
    if (command == "add") {
      reglist st;
      cout << "Введите имя: ";
      cin >> st.name;
      cout << "Введите фамилию: ";
      cin >> st.surname;
      while (!getDate(st.date));
      while (!getMoney(st.money));
      saveFile(st);
    }
    if (command == "read") {
      cout << endl << "Список:" << endl;
      List list;
      readFile(list);
      for (auto st : list) {
        cout << st.name << " " << st.surname << " " << st.date << " " << st.money << endl;
      }
    }
  }
  cout << endl << endl;
  return 0;
}

void saveFile(reglist &st) {
  std::ofstream file(PATH.data(), std::ios::app);
  if (file.is_open()) {
    file << st.name << " " << st.surname << " " << st.date << " " << st.money << endl;
    file.close();
  } else {
    cout << "[Ошибка] Не удалось открыть файл на запись" << endl;
  }
}

void readFile(List &list) {
  std::ifstream file(PATH.data());
  if (file.is_open()) {
    reglist st;
    while (file.good()) {
      st.name = "";
      file >> st.name;
      if (st.name.length() > 0) {
          file >> st.surname;
          file >> st.date;
          file >> st.money;
          list.push_back(st);
      }
    }
    file.close();
  } else {
    cout << "[Ошибка] Не удалось открыть файл на чтение" << endl;
  }
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

bool checkDate(const string_view &str) {
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
  Substrings subStrings = getSubStrings(str, '.');
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

Substrings getSubStrings(const string_view &str, const char &delimiter) {
  Substrings arr;
  for (size_t i {0}, j {0}; i < str.length(); i++) {
    if (str[i] == delimiter) { j++; }
    else { arr[j] += str[i]; }
  }
  return arr;
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

