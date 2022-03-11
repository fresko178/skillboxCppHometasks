#include <iostream>
#include <vector>
#include <filesystem>

using path = std::filesystem::path;

auto getFiles = [](path &p, const std::string ext) {
  std::vector<std::string> list;
  for (auto &x : std::filesystem::recursive_directory_iterator(p)) {
    if (x.is_regular_file() && x.path().extension().compare(ext)) {
      list.push_back(x.path().filename());
    }
  }
  return list;
};

int main(int argc, char *argv[])
{
  path p("/home/pasha/Downloads/abc");
  auto v = getFiles(p, "txt");
  for (auto x : getFiles(p, "txt")) {
    std:: cout << x << std::endl;
  }
  std::cout << std::endl;

  return 0;
}

