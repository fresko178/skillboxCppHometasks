#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
  cout << "Задача 2. " << endl << endl;
  vector<float> prices  {2.5f, 4.25f, 3.0f, 10.0};
  vector<size_t> purchases {1, 1, 0, 3};

  float sum = 0.0f;
  for (auto i : purchases) {
    sum += prices[i];
  }

  cout << "sum = " << sum << endl << endl;

  return 0;
}

