#ifndef REGISTER_H
#define REGISTER_H

#include <vector>
#include <iostream>

template<typename Key, typename Val>
class Register
{
  struct Pair
  {
    Key key;
    Val val;
  };

  Pair getPair(Key k, Val v)
  {
    return Pair {k, v};
  }

public:

  std::vector<Pair> Reg;

  void add(Key k, Val v)
  {
    Reg.push_back(getPair(k, v));
  }

  int find(Key k)
  {
    for (size_t i{0}; i < Reg.size(); i++)
    {
      if (Reg.at(i).key == k)
      {
        return i;
      }
    }
    return -1;
  }

  bool remove(Key k)
  {
    int index = find(k);
    if(index >= 0)
    {
      Reg.erase(Reg.begin() + index);
      return true;
    }
    return false;
  }

  void print()
  {
    for (size_t i{0}; i < Reg.size(); i++)
    {
      std::cout << "key = " << Reg.at(i).key
                << "  val = " << Reg.at(i).val << std::endl;
    }
  }

};

#endif
