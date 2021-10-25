#include <iostream>
#include "disk.h"
#include "gpu.h"
#include "ram.h"
#include "cpu.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout << "Задание 2. Проект симулятора работы компьютера" << endl;
  std::string command {""};
  while (command != "exit") {
    cout << "Введите одну из команд (sum, save, load, input, display, exit)" << endl;
    cin >> command;
    if (command == "input") {
      write();
    }
    if (command == "save") {
      save(read());
    }
    if (command == "load") {
      load(read());
    }
    if (command == "display") {
      display(read());
    }
    if (command == "sum") {
      cout << "сумма = " << computer(read()) << endl;
    }
  }

  return 0;
}

