#include "tree.h"
#include "mainbranch.h"

Tree::Tree() {
  branchesTree.resize(std::rand() % 3 + 3); // 3 - 5
}

void Tree::genBranche() {
  for (size_t i {0}; i < branchesTree.size(); i++) {
  std::cout << "new branch #" << i << std::endl;
    branchesTree[i].genElfs();
  }
}

Tree::~Tree() {
}

void Tree::find(std::string &name) {
  for (size_t i {0}; i < branchesTree.size(); i++) {
    branchesTree[i].findElfs(name);
  }
}
