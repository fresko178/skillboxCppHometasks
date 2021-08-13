#include <iostream>
#include <array>

using std::cout;
using std::endl;
using std::array;

constexpr int SIZE {5};

int main() {
  cout << "Задача 2" << endl;
//  array<int, SIZE> arr {2, 7, 11, 15};
  array<int, SIZE> arr {-1, -2, -4, 7, 11};
  int res = 9;
  for (size_t i {0}; i < SIZE - 1; i++) {
    for (size_t j {i + 1}; j < SIZE; j++) {
      if (arr[i] + arr[j] == res) { cout << arr[i] << " и " << arr[j]; }
    }
    cout << endl;
  }

  cout << endl << endl;

  return 0;
}

