#include <iostream>
#include <city.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout << "Задание 1. Реализация деревни эльфов" << endl;
  City msk;
  msk.genTree();
  std::cout << "Введите искомое имя: ";
  std::string name;
  std::cin >> name;
  msk.find(name);

  return 0;
}

