#include <iostream>
#include "simulation.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout << "Задание 1. Симулятор проведения операций" << endl;
  std::string commands [] {"scalpel", "hemostat", "tweezers", "suture"};
  std::string command {""};
  Point p1;   // первая координата
  Point p2;   // вторая координата
  Point cutStart; // координата начала разреза
  Point cutEnd;   // координата конца разреза
  for (int i {0}; i < 4; i++) {
    cout << "Введите одну из команд (scalpel, hemostat, tweezers, suture)" << endl;
    cin >> command;
    if (command == commands[i]) { // команды должны идти последовательно
      switch (i) {
        case 0 : {
          cutStart = enterCoord("Введите координаты начала разреза");
          cutEnd = enterCoord("Введите координаты конца разреза");
          scalpel(cutStart, cutEnd);
        }
        break;
        case 1 : {
          p1 = enterCoord("Введите координаты точки зажима");
          if (!checkCoord(cutStart, cutEnd, p1)) {
            cout << "координата зажима неверна, повторите ввод" << endl;
            i--; // откатываемся на предыдущий шаг
          } else {
            hemostat(p1);
          }
        }
        break;
        case 2 : {
          p1 = enterCoord("Введите координаты для пинцета");
          if (!checkCoord(cutStart, cutEnd, p1)) {
            cout << "координата пинцета неверна, повторите ввод" << endl;
            i--; // откатываемся на предыдущий шаг
          } else {
            tweezers(p1);
          }
        }
        break;
        case 3 : {
          p1 = enterCoord("Введите координаты начала шва");
          p2 = enterCoord("Введите координаты конца шва");
          if (!checkCoord(cutStart, cutEnd, p1) || !checkCoord(cutStart, cutEnd, p2)) {
            cout << "координаты шва неверны, повторите ввод" << endl;
            i--; // откатываемся на предыдущий шаг
          } else {
            suture(p1, p2);
          }
        }
        break;
      } // end switch
    } else {
      cout << "Введена неверная команда, повторите ввод" << endl;
      i--; // откатываемся на предыдущий шаг
    }
  } // end for
}

