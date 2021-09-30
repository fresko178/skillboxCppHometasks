#include <iostream>
#include <map>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using People = std::map<std::string, int>; // ключ= фамилия; значение= счётчик однофамильцев

void addSurname(People &, std::string &surname);
void printSurname(People &);

int main() {
  cout << "Задание 2. Регистратура" << endl << endl;
  People people;
  cout << "Вводите фамилии, вывод фамилии(next) выход(exit) вывести весь список(list)" << endl;
  std::string surname {""};
  while (true) {
    cin >> surname;
    if (surname == "next" || surname == "Next" || surname == "NEXT") {
      printSurname(people);
    } else if (surname == "exit") {
      return 0;
    } else if (surname == "list") {
      cout << "---- List -----" << endl;
      for(auto x : people) {
        cout << x.first << " " << x.second << endl;
      }
    } else {
      addSurname(people, surname);
    }
  }
  cout << endl << endl;
  return 0;
}

void addSurname(People &p, std::string &surname) {
  auto it = p.find(surname);
  if (it != p.end()) { // нашли запись
    it->second++; // увеличиваем кол. однофамильцев
  } else {
    p.insert(std::make_pair(surname, 1)); // добавляем новую запись
  }
}

void printSurname(People &p) {
  if (p.size() > 0) {
    auto it = p.begin();
    cout << "в регистратуру вызывается " << it->first << endl;
    it->second--; // уменьшаем кол. однофамильцев
    if (it->second < 1) { // в регистратуру вызван последний однофамилец
      p.erase(it); // удаляем последнего однофамильца из очереди
    }
  } else {
    cout << "в очереди никого нет! " << endl;
  }
}

