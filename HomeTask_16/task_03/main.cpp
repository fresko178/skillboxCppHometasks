#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::string_view;
using Vec = std::vector<string>;

Vec Pars(const string_view);

int main() {
  cout << "Калькулятор" << endl << endl;
  cout << "Введите выражение (<число> <+,-,*,/> <число>): ";
  string str;
  cin >> str; // т.к. без пробелов можно и cin
  string_view sv{str};
  Vec vec = Pars(sv); // теперь у нас 3 подстроки
  switch (vec[1][0]) {
    case '+': cout << "result: " << std::stod(vec[0]) + std::stod(vec[2]);
      break;
    case '-': cout << "result: " << std::stod(vec[0]) - std::stod(vec[2]);
      break;
    case '*': cout << "result: " << std::stod(vec[0]) * std::stod(vec[2]);
      break;
    case '/': cout << "result: " << std::stod(vec[0]) / std::stod(vec[2]);
      break;
  }

  cout << endl << endl;

  return 0;
}

// возвращает вектор строк, первое число, знак и третье число
Vec Pars(const string_view str) {
  string newStr = "";
  Vec vec;
  newStr += str[0]; // O(1)
  bool find = false; // признак того, что знак (не)найден
  for (size_t i = 1; i < str.length(); i++) { // O(n)
    if (!find && ('-' == str[i] || '+' == str[i] || '*' == str[i] || '/' == str[i])) { // шама ждёт знак
      vec.push_back(newStr); // запоминаем первое число
      newStr = str[i];
      vec.push_back(newStr); // теперь запоминаем знак
      find = true;
      newStr = "";
    } else {
      newStr += str[i];
    }
  }
  vec.push_back(newStr); // третье число

  return vec;
}

