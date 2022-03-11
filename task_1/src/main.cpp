#include <iostream>

int main(int argc, char *argv[])
{
  for (auto x : std::initializer_list<int> {1, 2, 3, 4, 5}) {
    std::cout << " " << x;
  }
  std::cout << std::endl;

  return 0;
}
