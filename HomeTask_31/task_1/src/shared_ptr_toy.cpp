#include "shared_ptr_toy.h"

Shared_ptr_toy::Shared_ptr_toy() : obj(new Toy("someName")), count(new int(1)) {
}

Shared_ptr_toy::Shared_ptr_toy(string name) : obj( new Toy(name)), count(new int(1)) {
}

Shared_ptr_toy::Shared_ptr_toy(Toy *toy) : obj(toy), count(new int(1)) {
}

Shared_ptr_toy::Shared_ptr_toy(const Shared_ptr_toy &toy) : obj(toy.obj), count(toy.count + 1) {
}

Shared_ptr_toy::~Shared_ptr_toy() { // деструктор
  *count -= 1;
  if (*count == 0) {
    cout << "(destructor) delete " << obj->getName() << endl;
    delete obj;
    delete count;
  }
}

Shared_ptr_toy& Shared_ptr_toy::operator = (const Shared_ptr_toy &other) { // оператор присваивания
  if (count != other.count && (*count - 1) == 0) {
    if (obj == nullptr) { cout << "delete Nothing" << endl; }
    else { cout << "delete " << obj->getName() << endl; }
    delete obj;
    delete count;
    obj = other.obj;
    *count = *other.count + 1;
  }
  return *this;
}

Toy* Shared_ptr_toy::getToy() {
  return obj;
}
