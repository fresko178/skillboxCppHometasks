#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

struct task {
  std::string name {""}; // имя задачи
  bool run = false;      // статус выполнения
  time_t time {0};       // время выполнения
};

using std::cout;
using std::cin;
using std::endl;
using std::string;
using ListTasks = std::vector<task>;

void begin(ListTasks &);
void end(ListTasks &);
void status(ListTasks &);

int main() {
  cout << "Задание 1. Реализация программы учёта времени" << endl;
  string command {""};
  ListTasks listTasks;
  while(command != "exit") {
    cout << "Введите команду:";
    cin >> command;
    if (command == "begin") { begin(listTasks); }
    else if (command == "end") { end(listTasks); }
    else if (command == "status") { status(listTasks); }
  }

  return 0;
}

void begin(ListTasks &listTasks) {
  end(listTasks);
  cout << "Введите название задачи: ";
  task newTask;
  cin >> newTask.name;
  newTask.run = true; // взводим текущую задачу
  newTask.time = time(nullptr); // фиксируем время
  listTasks.push_back(newTask);
}

void end(ListTasks &listTasks) {
  if(listTasks.size() > 0 && (listTasks.end() - 1)->run) { // текущая задача выполняется
    (listTasks.end() - 1)->run = false; // завершаем текущую задачу
    (listTasks.end() - 1)->time = time(nullptr) - (listTasks.end() - 1)->time; // время выполнения задачи
  }
}

void status(ListTasks &listTasks) {
  for (task i : listTasks) {
    std::tm *local = localtime(&i.time);
    if (!i.run) {
      local->tm_hour -= 3;
      cout << i.name << " " << std::put_time(local, "%H:%M:%S") << endl;
    } else {
      cout << "текущая задача: " << i.name << endl;
    }
  }
}

