#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

struct Man {
  std::string name {""}; // имя
  std::tm date;       // дата рождения
};

using std::cout;
using std::cin;
using std::endl;
using std::string;
using People = std::vector<Man>;

void findBirthday(People &);
void printBirthday(People &);
void putToList(People &, Man &);

int main() {
  cout << "Задание 2. Реализация программы напоминания о днях рождения" << endl;
  string name {""};
  People people;

  while(name != "end") { // создаём список дней рождений
    cout << "Введите имя:";
    cin >> name;
    if (name == "end") { break; }
    else {
      Man man;
      man.name = name;
      cout << "Введите дату рождения (год/месяц/день):";
      time_t t = time(nullptr);
      man.date = *localtime(&t);
      cin >> std::get_time(&man.date, "%Y/%m/%d");
      people.push_back(man);
    }
  }

  for (Man m : people) {
    cout << m.name << "  " << std::put_time(&m.date, "дата = %Y/%m/%d") << endl;
  }

  cout << endl;
  findBirthday(people);

  return 0;
}

void findBirthday(People &people) {
  std::time_t t = std::time(nullptr);
  std::tm curDate = *localtime(&t); // текущая дата
  std::tm tm {};
  bool find {true}; // продолжать ли поиск (если у кого-то сегодня день варенья искать близкую дату нет смысла)
  People equalBirthday; // список одинаковых дней рождения
  for (Man man : people) {
    if (man.date.tm_year == curDate.tm_year && man.date.tm_mon == curDate.tm_mon
        && man.date.tm_mday == curDate.tm_mday) {
      cout << "Сегодня день рождения у " << man.name << endl;
      find = false;
    }
    if (find && man.date.tm_year != curDate.tm_year) { // дни рождения в тек. году игнурируются
      if (find && tm.tm_year < man.date.tm_year) {
        putToList(equalBirthday, man);
        tm = man.date;
      } else if (find && tm.tm_year == man.date.tm_year
                      && tm.tm_mon < man.date.tm_mon) {
        putToList(equalBirthday, man);
        tm = man.date;
      } else if (find && tm.tm_year == man.date.tm_year
                      && tm.tm_mon == man.date.tm_mon
                      && tm.tm_mday < man.date.tm_mday) {
        putToList(equalBirthday, man);
        tm = man.date;
      } else if (find && tm.tm_year == man.date.tm_year
                      && tm.tm_mon == man.date.tm_mon
                      && tm.tm_mday == man.date.tm_mday) { // ближайшие даты совпадают
        putToList(equalBirthday, man);
      }
    }
  }

  if (find) { printBirthday(equalBirthday); }
}

void printBirthday(People &people) {
  if (people.size() > 0) {
    for (Man m : people) {
      cout << "ближайшее день рождения у " << m.name
           << std::put_time(&m.date, " дата = %m/%d") << endl << endl;
    }
  }
}

void putToList(People &p, Man &m) {
  if (p.size() > 0) {
    if ((p.end() - 1)->date.tm_year == m.date.tm_year
         && (p.end() - 1)->date.tm_mon == m.date.tm_mon
         && (p.end() - 1)->date.tm_mday == m.date.tm_mday) { // днирождения совпадают
      p.push_back(m);
    } else { // считаем, что найдено более близкое к тек. дате день рождения
      p.clear(); // всё предыдущие записи дней рождений стираем
      p.push_back(m); // и заносим новую запись
    }
  } else { // эта самая первая запись
    p.push_back(m);
  }
}

