#include "mainbranch.h"

MainBranch::MainBranch() {
  nameElf70lvl.resize(std::rand() % 2 + 2); // 2 - 3
}

void MainBranch::genElfs() {
  std::string name {""};
  for (size_t i {0}; i < nameElf70lvl.size(); i++) {
    std::cout << "Введите имя эльфа: " << std::endl;
    std::cin >> name;
    if (name != "None") { nameElf70lvl[i] = name; }
//    else { nameElf70lvl[i] = ""; }
  }
}

MainBranch::~MainBranch() {
}

void MainBranch::findElfs(std::string &name) {
  for (size_t i {0}; i < nameElf70lvl.size(); i++) {
    if (name == nameElf70lvl[i]) {
      std::cout << "кол. соседей = " << nameElf70lvl.size() - 1 << std::endl;
    }
  }
}
