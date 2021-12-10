#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

std::mutex access_cooking;
std::vector <std::string> orderBox;

void kitchen(std::string *, int);
void courier();

int main() {
  std::string dishes[5] {"pizza", "soup", "steak", "salad", "sushi"};
  std::thread th(courier);

  for (size_t i {0}; i < 10; i++) {
    std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 6 + 5));
    int index = std::rand() % 5;
    time_t t = time(nullptr); // фиксируем время получения заказа
    std::tm *local = std::localtime(&t);
    cout << "the order was received (" + dishes[index] + ")  " << local->tm_min << ":" << local->tm_sec << endl;
    std::thread cooking(kitchen, dishes, index);
    cooking.detach();
  }

  th.join();
  cout << "program close" << endl;
  return 0;
}

void kitchen(std::string *dishes, int index) {
  access_cooking.lock();
  time_t t = time(nullptr); // фиксируем время поступления заказа на кухню
  std::tm *local = std::localtime(&t);
  cout << "the order is accepted (" + dishes[index] + ")  " << local->tm_min << ":" << local->tm_sec << endl;
  std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 11 + 5));
  t = time(nullptr);  // фиксируем время приготовления заказа
  local = std::localtime(&t);
  cout << "the order is ready (" + dishes[index] + ")  " << local->tm_min << ":" << local->tm_sec << endl;
  orderBox.push_back(dishes[index]); // помещаем готовый заказ на стойку
  access_cooking.unlock();
}

void courier() {
  int countOrders {0}; // счётчик заказов
  while (countOrders < 10) {
    std::this_thread::sleep_for(std::chrono::seconds(30));
    countOrders += orderBox.size(); // курьер
    orderBox.clear();               // забирает заказы
    time_t t = time(nullptr); // фиксируем время выдачи заказов
    std::tm *local = std::localtime(&t);
    cout << "courier received orders    " << local->tm_min << ":" << local->tm_sec
         << "     countOrders = " <<  countOrders << endl;
  }
}

