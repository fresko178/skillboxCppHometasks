#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void way(size_t);
std::mutex access;

struct CrazyTrain {
  std::string name {""};
  int timeWay {0};
};

std::vector<CrazyTrain> crazyTrain(3);

int main() {

  for (size_t i {0}; i < 3; i++) {
    crazyTrain[i].name = 'A' + i;
    cout << "Enter travel time for the train " + crazyTrain[i].name + ": ";
    cin >> crazyTrain[i].timeWay;
    cout << endl;
  }

  std::thread train_A(way, 0);
  std::thread train_B(way, 1);
  std::thread train_C(way, 2);

  if (train_A.joinable()) { train_A.join(); }
  if (train_B.joinable()) { train_B.join(); }
  if (train_C.joinable()) { train_C.join(); }

  return 0;
}

void way(size_t numberTrain) {

  time_t currentTime = time(nullptr);
  for (int i {1}; i <= crazyTrain[numberTrain].timeWay; i++) {
    time_t sec {0};
    while (sec < currentTime + 1) {
      sec = time(nullptr);
    }
    currentTime++;
    if (i == crazyTrain[numberTrain].timeWay) {
      cout << "the train " << crazyTrain[numberTrain].name << " arrived" << endl;
      std::string command {""};
      access.lock();
      cout << "the train " << crazyTrain[numberTrain].name << " is waiting" << endl;
      while (command != "depart") {
        cout << crazyTrain[numberTrain].name + " departure request: ";
        cin >> command;
      }
      cout << "the train " << crazyTrain[numberTrain].name << " departed" << endl;
      access.unlock();
    }
  }

}

