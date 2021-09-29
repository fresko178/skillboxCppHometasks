#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using PhoneToUser = std::map<std::string, std::string>;
using Vec = std::vector<std::string>;
using UserToPhones = std::map<std::string, Vec>;

enum {ADD = 1, GETSURNAME, GETNUMBER};

void addSubscriber(PhoneToUser &, UserToPhones &);
void getSurname(PhoneToUser &p);
void getNumber(UserToPhones &p);

int main() {
  cout << "Задание 1. Телефонный справочник" << endl << endl;
  PhoneToUser phoneUser;
  UserToPhones userPhones;
  int command = {0};
  while (command != 4) {
    cout << endl << "Выберите команду введя номер пункта из списка: " << endl <<
            "1) добавить нового абонента" << endl <<
            "2) узнать фамилию абонента по номеру телефона" << endl <<
            "3) узнать телефон абонента по фамилии " << endl <<
            "4) выйти из программы" << endl;
    cin >> command;
    switch(command) {
      case ADD : addSubscriber(phoneUser, userPhones);
        break;
      case GETSURNAME: { getSurname(phoneUser); }
        break;
      case GETNUMBER: { getNumber(userPhones); }
        break;
      default: return 0;
    }
  }
  cout << endl << endl;
  return 0;
}

void addSubscriber(PhoneToUser &phoneUser, UserToPhones &userPhones) {
  std::string number {""};
  std::string name {""};
  cout << "введите телефон абонента: ";
  cin >> number;
  cout << "введите имя абонента: ";
  cin.get();
  getline(std::cin, name);
  cout << endl;
  auto iter = phoneUser.insert(std::make_pair(number, name)); // заводим новую запись пользователя
  if (iter.second) { // запись внеслась в мапу
    auto it = userPhones.find(name); // ищем абонента по имени
    if (it != userPhones.end()) { // нашли пользователя
      it->second.push_back(number); // сохраняем очередной номер телефона абонента
    } else { // не нашли пользователя
      Vec vec {number};
      userPhones.insert(std::make_pair(name, vec)); // заводим нового пользователя
    }
  }
}

void getSurname(PhoneToUser &p) {
  cout << "Введите номер телефона: ";
  std::string number {""};
  cin >> number;
  auto it = p.find(number);
  if (it != p.end()) { cout << "результат " << it->second << endl; }
  else { cout << "Такого номера телефона не найдено" << endl; }
}

void getNumber(UserToPhones &phones) {
  cout << "Введите имя абонента: ";
  std::string name {""};
  cin.get();
  getline(std::cin, name);
  auto it = phones.find(name);
  if (it != phones.end()) { // абонент найден
    for (auto vec : it->second) {
      cout << " " << vec; // печатаем список номеров
    }
  } else {
    cout << "Такого абонента не найдено" << endl;
  }
  cout << endl << endl;
}

