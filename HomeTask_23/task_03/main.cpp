#include <iostream>

//#define SPRING
//#define SUMMER
#define AUTUMN
//#define WINTER

using std::cout;
using std::endl;

int main() {
  cout << "Задание 3. Вывод времени года" << endl;

  #ifdef SPRING
    cout << "Весна "<< endl;
  #endif

  #ifdef SUMMER
    cout << "Лето " << endl;
  #endif

  #ifdef AUTUMN
    cout << "Осень "<< endl;
  #endif

  #ifdef WINTER
    cout << "Зима "<< endl;
  #endif

  return 0;
}

