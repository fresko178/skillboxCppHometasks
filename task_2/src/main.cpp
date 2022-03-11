#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

auto howMany = [](std::vector<int> &v) {
  auto uniq_vec = std::make_unique<std::vector<int>>();
  std::unordered_set<int> s {v.begin(), v.end()};
  for (auto x : s) {
    uniq_vec->push_back(x);
  }
  return uniq_vec;
};

int main(int argc, char *argv[])
{
  std::vector<int> v {1, 2, 3, 2, 4, 2, 3};
  auto p = howMany(v);
  for (auto x : *p) {
    std:: cout << x << " ";
  }

  std::cout << std::endl;

  return 0;
}

