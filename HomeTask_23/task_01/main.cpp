#include <iostream>

#define DAY1 "MONDAY"
#define DAY2 "TUESDAY"
#define DAY3 "WEDNESDAY"
#define DAY4 "THURSDAY"
#define DAY5 "FRIDAY"
#define DAY6 "SATURDAY"
#define DAY7 "SUNDAY"
#define CONC(a) DAY ## a

using std::endl;
using std::cout;
using std::cin;

int main() {
  cout << "Задание 1. Реализация продвинутый ввод и вывод дней недели" << endl << endl;
  cout << "Enter the number of the day: ";
  int numDay {0};
  cin >> numDay;
  switch (numDay) {
    case 1 : cout << CONC(1) << endl;
      break;
    case 2 : cout << CONC(2) << endl;
      break;
    case 3 : cout << CONC(3) << endl;
      break;
    case 4 : cout << CONC(4) << endl;
      break;
    case 5 : cout << CONC(5) << endl;
      break;
    case 6 : cout << CONC(6) << endl;
      break;
    case 7 : cout << CONC(7) << endl;
      break;
    default: cout << "Error: Wrong number!" << endl;
  }

  return 0;
}

