#include <iostream>
#include <phone.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout << "Задание 2. Реализация программы симуляции мобильного телефона" << endl;
  Phone phone = Phone();
  std::string command {""};
  while (command != "exit") {
    cout << "Введите одну из команд (add, call, sms, exit): " << endl;
    cin >> command;
    if (command == "add") {
      phone.newRecord();
    }
    if (command == "call") {
      phone.call();
    }
    if (command == "sms") {
      phone.sms();
    }
  }

  return 0;
}

