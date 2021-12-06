#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void swim(size_t numberSportsman);
std::mutex access;

struct Sportsman {
  std::string name {""};
  int speed {0};
};

std::vector<Sportsman> sportsman(6);
const int LENGTH {100};

int main() {

  for (size_t i {0}; i < 6; i++) {
    cout << "Введите имя спортсмена " + std::to_string(i + 1) + ": ";
    cin >> sportsman[i].name;
    cout << "Введите скорость спортсмена " + std::to_string(i + 1) + " (скорость в мс): ";
    cin >> sportsman[i].speed;
    cout << endl;
  }

  std::thread man1_thread(swim, 0);
  std::thread man2_thread(swim, 1);
  std::thread man3_thread(swim, 2);
  std::thread man4_thread(swim, 3);
  std::thread man5_thread(swim, 4);
  std::thread man6_thread(swim, 5);

  if (man1_thread.joinable()) { man1_thread.join(); }
  if (man2_thread.joinable()) { man2_thread.join(); }
  if (man3_thread.joinable()) { man3_thread.join(); }
  if (man4_thread.joinable()) { man4_thread.join(); }
  if (man5_thread.joinable()) { man5_thread.join(); }
  if (man6_thread.joinable()) { man6_thread.join(); }

  return 0;
}

void swim(size_t numberSportsman) {

  access.lock();
  time_t steps =  LENGTH / sportsman[numberSportsman].speed;
  if ((steps * sportsman[numberSportsman].speed) < LENGTH) { steps++; }
  access.unlock();

  time_t currentTime = time(nullptr);
  int length {0};
  for (int i {1}; i <= steps; i++) {
    time_t sec {0};
    while (sec < currentTime + 1) {
      sec = time(nullptr);
    }
    currentTime++;
    access.lock();
    length += sportsman[numberSportsman].speed;
    if (length < LENGTH) { cout << sportsman[numberSportsman].name << "  " << length << endl; }
    else { cout << sportsman[numberSportsman].name  << "  finish" << endl; }
    access.unlock();
  }

}
