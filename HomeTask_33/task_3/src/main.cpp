#include <iostream>
#include "register.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
  Register<int, int> reg;
  int key, val;
  string command{""};

  while(command != "exit")
  {
    cout << "Enter a command: ";
    cin >> command;

    if (command == "exit")
    { break; }

    if (command == "add")
    {
      cout << "Enter key, value: ";
      cin >> key >> val;
      reg.add(key, val);
    }

    if (command == "find")
    {
      cout << "Enter key: ";
      cin >> key;
      int i = reg.find(key);
      if (i >= 0)
      {
        cout << "key = " << reg.Reg.at(i).key << "  val = " << reg.Reg.at(i).val << endl;
      }
      else
      {
        cout << "not found" << endl;
      }
    }

    if (command == "remove")
    {
      cout << "Enter key: ";
      cin >> key;
      cout << "remove " << reg.remove(key) << endl;
    }

    if (command == "print")
    {
      reg.print();
    }
  }

  cout << "program close" << std::endl;
  return 0;
}
