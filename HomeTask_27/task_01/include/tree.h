#ifndef TREE_H
#define TREE_H

#include "mainbranch.h"

class Tree {
public:
  std::vector<class MainBranch> branchesTree;
  Tree();
  ~Tree();
  void genBranche();
  void find(std::string &);
};

#endif // TREE_H
