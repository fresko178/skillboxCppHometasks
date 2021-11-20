#ifndef CITY_H
#define CITY_H
#include "tree.h"

class City {
  std::vector <class Tree> city;
public:
  City();
  ~City();
  void genTree();
  void find(std::string &);
};

#endif // CITY_H
