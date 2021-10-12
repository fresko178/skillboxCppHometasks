#include <iostream>

constexpr int SIZE {10};

using std::cout;
using std::cin;
using std::endl;

#define GETPASSENGERS(wagons) \
  for (int i {0}; i < SIZE; i++) { \
    cout << "Введите число пассажиров " << "вагон " << i + 1 << ": "<< endl; \
    cin >> wagons[i]; \
  }

#define OVERFLOW(wagons) \
  for (int i {0}; i < SIZE; i++) { \
    if (wagons[i] > 20) { \
      cout << "Вагон " << i + 1 << " переполнен" << endl; \
    } \
  }

#define EMPTYSPACES(wagons) \
  for (int i {0}; i < SIZE; i++) { \
    if (wagons[i] < 20) { \
      cout << "Вагон " << i + 1 << " имеет пустые места" << endl; \
    } \
  }

#define SUM(wagons) \
  int sum {0}; \
  for (int i {0}; i < SIZE; i++) { \
    sum += wagons[i]; \
  } \
  cout << "Общее кол. пассажиров " << sum << endl;


int main() {
  int wagons[SIZE];
  GETPASSENGERS(wagons);
  OVERFLOW(wagons);
  EMPTYSPACES(wagons);
  SUM(wagons);
  return 0;
}

