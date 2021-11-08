#include <iostream>
#include "phone.h"
#include "record.h"

using std::cout;
using std::cin;
using std::endl;

Phone::Phone() {
}

Phone::~Phone() {
}

void Phone::newRecord() {
  Record rec;
  cout << "Введите имя нового контакта: ";
  cin >> rec.name;
  cout << "Введите телефон нового контакта: ";
  cin >> rec.number;
  addressBook.push_back(rec);
}

void Phone::call() {
  cout << "Укажите контактные данные для звонка: ";
  std::string str;
  cin >> str;
  bool found {false};
  for (auto item : addressBook) {
    if (str == item.name || str == item.number) {
      cout << "CALL to " << item.number << endl;
      return;
    }
  }

  if (!found) {
    cout << "Контактных данных не обнаружено!" << endl;
  }
}

void Phone::sms() {
  std::cout << "Введите текст сообщения: ";
  std::string msg;
  cin.get();
  std::getline(cin, msg);
  cout << "Укажите контактные данные для sms: ";
  std::string str;
  cin >> str;
  bool found {false};
  for (auto item : addressBook) {
    if (str == item.name || str == item.number) {
      cout << "SMS to " << item.number << endl;
      cout << "текст сообщения:  " << msg << endl;
      return;
    }
  }

  if (!found) {
    cout << "Контактных данных не обнаружено!" << endl;
  }
}
