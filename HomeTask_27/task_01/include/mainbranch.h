#ifndef MAINBRANCH_H
#define MAINBRANCH_H

#include <iostream>
#include <vector>

class MainBranch {
  std::vector<std::string> nameElf70lvl;
public:
  MainBranch();
  ~MainBranch();
  void genElfs();
  void findElfs (std::string &);
};

#endif // MAINBRANCH_H
