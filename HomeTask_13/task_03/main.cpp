#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

void printDB(const std::vector<int> &);

int main() {
  cout << "Задача 3. " << endl;
  cout << "Введите значения в базу данных (-1 выход) " << endl << endl;

  std::vector<int> vecDB;
  vecDB.reserve(20);
  int x = 0;
  do {
    cin >> x;
    if (x != -1) {
      if (vecDB.size() == vecDB.capacity()) { vecDB.erase(vecDB.begin()); }
      vecDB.push_back(x);
    }
  } while(x != -1);
  cout << "vector: ";
  printDB(vecDB);
  cout << endl << endl;

  return 0;
}

void printDB(const std::vector<int> &vecDB) {
  for (auto &i : vecDB) {
    cout << i << " ";
  }
}

