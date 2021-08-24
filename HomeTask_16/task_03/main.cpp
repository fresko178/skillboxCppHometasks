#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string InsertSpaces(const string &);

int main() {
  cout << "Калькулятор" << endl << endl;
  std::stringstream strBuffer;
  cout << "Введите выражение (<число> <+,-,*,/> <число>): ";
  string str;
  cin >> str;
  strBuffer << InsertSpaces(str); // теперь у нас 3 подстроки
  strBuffer >> str; // извлекаем первую подстроку т.е. число
  double num1 = std::stod(str);
  string sign;
  strBuffer >> sign; // извлекаем вторую подстроку, она всегда будет знак
  strBuffer >> str; // извлекаем третью подстроку т.е. число
  if (sign == "+") { cout << "result: " << num1 + std::stod(str); }
  else if (sign == "-") { cout << "result: " << num1 - std::stod(str); }
  else if (sign == "*") { cout << "result: " << num1 * std::stod(str); }
  else if (sign == "/") { cout << "result: " << num1 / std::stod(str); }
  cout << endl << endl;

  return 0;
}

// разделяет строку на подстроки пробелами
string InsertSpaces(const string &str) {
  string newStr = "";
  newStr += str[0]; // O(1)
  bool find = false; // признак того, что знак (не)найден
  for (size_t i = 1; i < str.length(); i++) { // O(n)
    if (!find && ('-' == str[i] || '+' == str[i] || '*' == str[i] || '/' == str[i])) { // шама ждёт знак
      newStr = newStr + " " + str[i] + " ";
      find = true;
    } else {
      newStr += str[i];
    }
  }
  return newStr;
}

