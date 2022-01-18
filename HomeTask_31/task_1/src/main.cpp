#include "shared_ptr_toy.h"

Shared_ptr_toy make_shared_toy(const string name = "toyDefault") {
  return Shared_ptr_toy(name);
}

int main() {
  Shared_ptr_toy toy1(nullptr);
  auto p1 = make_shared_toy("Stick");
  auto p2 = make_shared_toy();
  auto toy2 = p1 = toy1 = p2;
  std::cout << "name = " << toy2.getToy()->getName() << std::endl;

  cout << "program close" << endl;
  return 0;
}

