#include <iostream>
#include "animal.h"
#include "cat.h"
#include "dog.h"
#include <string.h>

using std::cout;
using std::cin;
using std::endl;

void meeting(Animal *, Animal *);

int main() {
  Animal *a1 = new Cat();
  Animal *b1 = new Dog();
  meeting(a1, a1);
  meeting(a1, b1);
  meeting(b1, a1);
  meeting(b1, b1);

  delete a1; a1 = nullptr;
  delete b1; b1 = nullptr;

  cout << "program close" << endl;
  return 0;
}

void meeting(Animal *obj1, Animal *obj2) {
  if (strcmp(obj1->get(), "Bark") == 0 && strcmp(obj2->get(), "Bark") == 0) {
      cout << "Woof Woof" << endl;
  } else if (strcmp(obj1->get(), "Meow") == 0 && strcmp(obj2->get(), "Meow") == 0) {
      cout << "Purr Purr" << endl;
  } else {
    cout << obj1->get() << " " << obj2->get() << endl;
  }
}
