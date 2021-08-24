#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
  cout << "Сшиватель дробных чисел" << endl << endl;
  std::string whole = "";
  std::string fractional = "";
  cout << "Введите целую часть числа: ";
  cin >> whole;
  cout << "Введите дробную часть числа: ";
  cin >> fractional;
  cout << "result: " << std::stof(whole + "." + fractional);

  cout << endl << endl;

  return 0;
}

