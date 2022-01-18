#ifndef TOY_H
#define TOY_H

#include <iostream>

using std::string;

class Toy {
  string name; // название игрушки

public:
  Toy(string );
  Toy();
  string getName() const;
  ~Toy();
};

#endif // TOY_H
