#ifndef PHONE_H
#define PHONE_H

#include <vector>
#include "record.h"

class Phone {
  using AddressBook = std::vector<Record>;
  AddressBook addressBook;

public:
  Phone();
  ~Phone();
  void newRecord();
  void call();
  void sms();
};

#endif // PHONE_H
