#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool checkWholeAddress(string);
bool checkFirstPart(string);
bool checkSecondPart(string);

int main() {
  string str = "";
  cout << "Задание 2. Проверка корректности email-адреса" << endl;
  cout << "Введите email адрес: ";
  std::getline(cin, str);

  if (checkWholeAddress(str)) {
    size_t pos = str.find("@");
    if (checkFirstPart(str.substr(0, pos) ) && checkSecondPart(str.substr(pos + 1))) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }

  return 0;
}

bool checkWholeAddress(string str) {
  if (str.find("..") != string::npos) {
    return false; // недопустимое кол. точек идущих подрят
  }
  if (std::count(str.begin(), str.end(), '@') != 1) {
    return false; // недопустимое кол. '@'
  }

  return true;
}

bool checkFirstPart (string str) {
  if (str.length() < 1 || str.length() > 64) {
    return false; // недопустимая длина
  }
  if (*str.begin() == '.') {
    return false; // недопустимый первый символ
  }
  if (str.find_first_not_of("1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'*+-/=?^_`{|}~.") != string::npos) {
    return false; // в строке присутствуют недопустимые символы
  }

  return true;
}

bool checkSecondPart(string str) {
  if (str.length() < 1 || str.length() > 63) {
    return false; // недопустимая длина
  }
  if (*str.end() == '.') {
    return false; // недопустимый последний символ
  }
  if (str.find_first_not_of("1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-.") != string::npos) {
    return false; // в строке присутствуют недопустимые символы
  }

  return true;
}

