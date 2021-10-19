#include <iostream>
#include <ctime>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

int main() {
  cout << "Задание 3. Реализация программы таймера" << endl;
  cout << "Введите кол. минут и секунд (мин:сек 00:00)  ";
  time_t t = time(nullptr);
  std::tm tm = *localtime(&t);
  cin >> std::get_time(&tm, "%M:%S");
  cout << endl;
  time_t currentTime = time(nullptr);
  for (time_t amountSec = tm.tm_min * 60 + tm.tm_sec; amountSec > 0; amountSec--) {
    time_t sec {0};
    while (sec < currentTime + 1) {
      sec = time(nullptr);
    }
    currentTime++;
    cout << "remains seconds = " << amountSec << endl;
  }
  cout << "DING! DING! DING!" << endl;

  return 0;
}

