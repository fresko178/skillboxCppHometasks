#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using Vec = std::vector<int>;

void swap(Vec &, int *);
void printVec(const Vec &);
void printArr(const int *begin, const int *end);

int main() {
  cout << "Задача 1." << endl << endl;

  Vec vec {1, 2, 3, 4};
  int arr[] {5, 6, 7, 8};
  cout << "vec = ";
  printVec(vec);
  cout << "arr = ";
  printArr(arr, arr + 4);
  cout << "after swap" << endl;
  swap(vec, arr);
  cout << "vec = ";
  printVec(vec);
  cout << "arr = ";
  printArr(arr, arr + 4);

  cout << endl << endl;
  return 0;
}

void swap(Vec &vec, int *arr) {
  int temp {0};
  for (size_t i {0}; i < vec.size(); i++) {
    temp = vec[i];
    vec[i] = arr[i];
    arr[i] = temp;
  }
}

void printVec(const Vec &vec) {
  for(auto i : vec) { // &i экономим на операции копировании значения в переменную i
    cout << " " << i;
  }
  cout << endl;
}

void printArr(const int *begin, const int *end) {
  for (auto *p = begin; p != end; p++) {
    cout << " " << *p;
  }
  cout << endl;
}

