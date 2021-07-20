#include <iostream>
#include <algorithm>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;

const int SIZE {4};

bool checkWholeAddress(string);
array<string, SIZE> getSubStrings(string);

int main() {
  string str = {""};
  cout << "Задание 3. Валидация IP-адреса" << endl;
  cout << "Введите IP адрес: ";
  std::getline(cin, str);

  if (checkWholeAddress(str)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}

bool checkWholeAddress(string str) {
  if (str.length() < 7 || str.length() > 15) {
    return false; // недопустимая длина
  }
  if (std::count(str.begin(), str.end(), '.') != 3) {
    return false; // недопустимое кол. '.'
  }
  if (str.find("..") != string::npos) {
    return false; // недопустимое кол. точек идущих подрят
  }
  if (*str.begin() == '.' || *str.end() == '.') {
    return false; // недопустимый первый или последний символ
  }
  array<string, SIZE> subStrings = getSubStrings(str);
  for (size_t i = 0; i < SIZE; i++) {
    if (subStrings[i].find_first_not_of("1234567890") != string::npos) {
      return false; // в строке присутствуют недопустимые символы
    } else {
      int num = std::stoi(subStrings[i], nullptr, 10);
      if (num > 255) {
        return false; // некорректное значение
      }
    }
    if (subStrings[i][0] == '0' && subStrings[i].length() > 1) {
      return false; // лишний '0'
    }
  }

  return true;
}

array<string, SIZE> getSubStrings(string str) {
  array<string, SIZE> subStrings;
  for (size_t i = 0, j = 0; i < str.length(); i++) {
    if(str[i] == '.') { j++; }
    else { subStrings[j] += str[i]; }
  }
  return subStrings;
}

