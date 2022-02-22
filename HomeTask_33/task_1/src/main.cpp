#include <iostream>
#include <map>
#include "myexceptions.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

std::map <string, unsigned int> Basket;

void add(string, unsigned int);
void remove(string, unsigned int);

int main()
{
  string name {"qwe"};
  unsigned int count {100};
  string command {""};

  while (command != "exit")
  {
    cout << "Enter one of the commands (add, remove, exit)" << endl;
    cin >> command;
    if (command == "exit")
      continue;

    cout << "Enter the name of the product and its quantity" << endl;
    cin >> name;
    cin >> count;

    try {
      if (command == "add") {
        add(name, count);
      }
      if (command == "remove") {
        remove(name, count);
      }
    } catch (const NameEmpty &e) {
      std::cerr << e.what() << endl;
    } catch (const CountEmpty &e) {
      std::cerr << e.what() << endl;
    } catch (const BasketEmpty &e) {
      std::cerr << e.what() << endl;
    }
  }

  std::cout << "program close" << std::endl;
  return 0;
}

void add(string name, unsigned int count)
{
  if (name.size() == 0)
  {
    throw NameEmpty();
  }
  else if (count < 1)
  {
    throw CountEmpty();
  }
  else
  {
    Basket.insert(std::make_pair(name, count));
  }
}

void remove(string name, unsigned int count)
{
  std::map<string, unsigned int>::iterator it = Basket.find(name);

  if (Basket.size() == 0)
  {
    throw BasketEmpty();
  }
  else if (it->second < count)
  {
    throw std::invalid_argument("too many count");
  }
  else
  {
    it->second -= count;
    if (it->second == 0)
    {
      it = Basket.erase(it);
    }
  }
}
