#ifndef SHARED_PTR_TOY_H
#define SHARED_PTR_TOY_H
#include "toy.h"

using std::cout;
using std::endl;

class Shared_ptr_toy {
  Toy *obj {nullptr};
  int *count {nullptr}; // почему-то обязательно после obj

public:
  Shared_ptr_toy();
  Shared_ptr_toy(string);
  Shared_ptr_toy(Toy *);
  Shared_ptr_toy(const Shared_ptr_toy &);
  ~Shared_ptr_toy();
  Shared_ptr_toy& operator = (const Shared_ptr_toy &);
  Toy* getToy();
};

#endif // SHARED_PTR_TOY_H
