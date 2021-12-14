#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Dog : public Animal {
public:
  Dog();
  ~Dog();
  virtual char* get();
};

#endif // DOG_H
