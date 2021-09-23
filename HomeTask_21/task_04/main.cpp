#include <iostream>
#include <iomanip>
#include <fstream>
#include "header.h"

using std::endl;
using std::cout;
using std::cin;
using std::rand;

int main() {
  cout << "Задание 4. Реализация ролевой пошаговой игры" << endl << endl;
  Persons persons(6);
  for (size_t i {0}; i < persons.size() - 1; i++) { // инициализируем врагов
    persons[i] = createCharacter("Enemy #" + std::to_string(i + 1), rand() % 101 + 50, rand() % 51, rand() % 16 + 15, 'E');
    coordinateGeneration(persons[i]); // генерируем случайные координаты врагам
  }
  cout << "Создание персонажа:" << endl << "Введите имя: ";
  cin >> persons[5].name;
  cout << "Введите очки здоровья: ";
  cin >> persons[5].health;
  cout << "Введите очки брони: ";
  cin >> persons[5].armor;
  cout << "Введите очки наносимого урона: ";
  cin >> persons[5].damage;
  persons[5].image = 'P';
  coordinateGeneration(persons[5]); // генерируем случайные координаты герою
  separation(persons); // герой не должен вначале игры попадать на врагов

  cout << endl;
  Map map(SIZE, std::vector<char>(SIZE, FILLER));
  characterPlacement(map, persons); // размещаем персонажей
  printPersons(persons); //
  cout << endl;
  printMap(map);

  while (!playerTurn(map, persons));   // первый игрок приготовиться
  cout << endl << "Игра окончена !" << endl;
  cout << endl << endl;
  return 0;
}

Character createCharacter(const std::string_view &name, int health, int armor, int damage, char image) {
  Character c;
  c.name = name;
  c.health = health;
  c.armor = armor;
  c.damage = damage;
  c.image = image;
  coordinateGeneration(c);
  return c;
}

void coordinateGeneration(Character &c) {
  if (c.health > 0) { // персонаж ещё живой
    c.coordinates.x = rand() % SIZE;
    c.coordinates.y = rand() % SIZE;
  }
}

void printMap(const Map &map) {
  cout << "   ";
  for (int col {0}; col < SIZE; col++) { // вывод названия столбцов
    cout << std::right << std::setw(3) << col;
  }
  cout << endl;
  for (size_t i {0}; i < SIZE; i++) {
    cout << std::right << std::setw(3) << i;
    for (size_t j {0}; j < SIZE; j++) {
      cout << std::right << std::setw(3) << map[i][j]; // отрисовываем поле боя
    }
    cout << endl;
  }
}

bool playerTurn(Map &map, Persons &persons) {
  int command {0};
  bool gameOver {false}; // игра продолжается
  while (command < 1 || command > 6) {
    cout << endl << "Выберите команду введя номер пункта из списка: " << endl <<
            "1) left" << endl << "2) right" << endl << "3) top" << endl << "4) bottom" << endl
         << "5) save game" << endl << "6) load game" << endl;
    cin >> command;
    if (command < 1 || command > 6) {
      cout << "[ОШИБКА] Указана неверная команда повторите ввод" << endl;
    }
  }

  switch(command) {
    case SAVE : {
      saveGame(persons);
      return false;
    }
    case LOAD : {
      loadGame(map, persons);
      printMap(map);
      return false;
    }
  }

  for (size_t i {0}; i < persons.size(); i++) {
    map[persons[i].coordinates.y][persons[i].coordinates.x] = FILLER; // затираем следы
    if (i == persons.size() - 1) { moveCharacter(persons[i], command); } // получаем новые координаты герою
    else { moveCharacter(persons[i], rand() % 3 + 1); } // получаем новые координаты врагу
  }

  if (battle(persons) || (persons[0].health < 1 && persons[1].health < 1
      && persons[2].health < 1 && persons[3].health < 1 && persons[4].health < 1)) {
    gameOver = true; // произошло сражение, герой погиб или все враги богибли, игра окончена
  }
  printPersons(persons);
  characterPlacement(map, persons); // размещаем изображения персонажей на поле боя

  printMap(map);
  return gameOver;
}

void moveCharacter (Character &c, const int commandCode) {
  switch(commandCode) {
    case LEFT   : if (c.coordinates.x - 1 < SIZE) c.coordinates.x--;
      break;
    case RIGHT  : if (c.coordinates.x + 1 < SIZE) c.coordinates.x++;
      break;
    case TOP    : if (c.coordinates.y - 1 < SIZE) c.coordinates.y--;
      break;
    case BOTTOM : if (c.coordinates.y + 1 < SIZE) c.coordinates.y++;
      break;
  }
}

void characterPlacement(Map &map, const Persons &persons) {
  for (size_t i {0}; i < persons.size(); i++) {
    if (i == persons.size() - 1 && persons[i].health > 0) { // это герой и он жив
      map[persons[i].coordinates.y][persons[i].coordinates.x] = persons[i].image;
    } else if (persons[i].health > 0) { // если враг жив
      map[persons[i].coordinates.y][persons[i].coordinates.x] = persons[i].image;
    }
  }
}

bool battle(Persons &persons) {
  for (size_t i {0}; i < persons.size() - 1; i++) {
    if (persons[5].coordinates.x == persons[i].coordinates.x
        && persons[5].coordinates.y == persons[i].coordinates.y
        && persons[i].health > 0) { // герой столкнулся с живым врагом
      if (takeDamage(persons[5], persons[i].damage)) { // герой умер
        persons[5].image = FILLER; // стираем изображение героя
        return true;
      }
      if (takeDamage(persons[i], persons[5].damage)) { // враг умер
        persons[i].image = FILLER; // стираем изображение врага
      }
    }
  }
  return false;
}

bool takeDamage(Character &character, const int damage) {
  character.armor -= damage;
  if (character.armor < 0) { // броню разбили
    character.health += character.armor;
    character.armor = 0;
    if (character.health < 1) { return true; } // персонаж убит
  }
  return false;
}

void printPersons(Persons &persons) {
  for (auto &p : persons) {
    cout << p.name + " x=" << p.coordinates.x << "  y=" << p.coordinates.y
         << "  health = " << p.health << "  armor = " << p.armor << endl;
  }
}

void separation (Persons &persons) {
  for (size_t i {0}; i < persons.size() - 1; i++) {
    if (persons[5].coordinates.x == persons[i].coordinates.x
        && persons[5].coordinates.y == persons[i].coordinates.y) { // если координаты врага с героем совпали
      coordinateGeneration(persons[5]);
      i = 0;
    }
  }
}

void saveGame(Persons &persons) {
  std::ofstream file("save.txt");
  if (file.is_open()) {
    for(auto p : persons) {
      file << p.name << endl << p.health << endl << p.armor << endl << p.damage << endl << p.image << endl
           << p.coordinates.x << endl << p.coordinates.y << endl;
    }
    file.close();
  } else {
    cout << "[Ошибка] Не удалось открыть файл на запись" << endl;
  }
}

void loadGame(Map &map, Persons &persons) {
  std::ifstream file("save.txt");
   if (file.is_open()) {
     std::string str {""};
     for (size_t i {0}; i < persons.size(); i++) {
       std::getline(file, persons[i].name);
       file >> str;
       persons[i].health = std::stoi(str);
       file >> str;
       persons[i].armor =  std::stoi(str);
       file >> str;
       persons[i].damage =  std::stoi(str);
       file >> str;
       persons[i].image =  str[0];
       file >> str;
       persons[i].coordinates.x =  std::stoul(str);
       file >> str;
       persons[i].coordinates.y =  std::stoul(str);
       std::getline(file, str);
     }
     file.close();
     for (size_t i {0}; i < SIZE; i++) {
       for (size_t j {0}; j < SIZE; j++) {
         map[i][j] = FILLER; // очищаем карту
       }
     }
     for (size_t i {0}; i < persons.size(); i++) {
       map[persons[i].coordinates.y][persons[i].coordinates.x] = persons[i].image; // размещаем персонажей
     }
   } else {
     cout << "[Ошибка] Не удалось открыть файл на чтение" << endl;
   }
}

