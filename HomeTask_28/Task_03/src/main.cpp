#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using std::cout;
using std::cin;
using std::endl;

std::mutex access_cooking;
std::mutex access_order;
std::vector <std::string> orderBox;

void kitchen(std::string *, int);
int courier();

int main() {
  std::string dishes[5] {"pizza", "soup", "steak", "salad", "sushi"};

  std::thread th(courier);

  for (size_t i {0}; i < 10; i++) {
    std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 6 + 5));
    int index = std::rand() % 5;
    cout << "the order was received (" + dishes[index] + ")" << endl;
    std::thread cooking(kitchen, dishes, index);
    cooking.detach();
  }

  th.join();
  cout << "program close" << endl;
  return 0;
}

void kitchen(std::string *dishes, int index) {
  access_cooking.lock();
  cout << "the order is accepted (" + dishes[index] + ")" << endl;
  std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 11 + 5));
  cout << "the order is ready (" + dishes[index] + ")" << endl;
  orderBox.push_back(dishes[index]);
  access_cooking.unlock();
}

int courier() {
  int countOrders {0};
  while (countOrders < 10) {
    std::this_thread::sleep_for(std::chrono::seconds(30));
    access_order.lock();
    countOrders += orderBox.size();
    orderBox.clear();
    cout << "courier received orders" << endl;
    cout << "countOrders = " <<  countOrders << endl;
    access_order.unlock();
  }

  return countOrders;
}

