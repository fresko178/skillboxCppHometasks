#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <string_view>
#include <vector>

/// команды передвижения по полю боя
enum {LEFT = 1, RIGHT, TOP, BOTTOM, SAVE, LOAD};

/// координаты положения персонажа
struct Coordinates {
  size_t x {0};
  size_t y {0};
};

/// персонаж
struct Character {
  std::string name {""};   // имя
  int health {0};          // здоровье
  int armor  {0};          // броня
  int damage {0};          // сила удара
  char image {0};          // изображение персонажа
  Coordinates coordinates; // координаты персонажа
};

/// символ заполнения поля боя '.'
constexpr char FILLER {'.'};
/// 40
constexpr int SIZE {40};
/// поле сражения
using Map = std::vector<std::vector<char>>;
/// персонажы
using Persons = std::vector<Character>;

/// создаёт персонажа
Character createCharacter(const std::string_view &name, int health, int armor, int damage, char image);
/// генерирует координаты положения персонажа
void coordinateGeneration(Character &);
/// вывод поля сражения
void printMap(const Map &);
/// перемещение, устанавливает новые координаты персонажу
void moveCharacter(Character &, const int commandCode);
/// ход игрока, возвращает true если игра закончилась
bool playerTurn(Map &, Persons &);
/// размещение персонажей на поле боя
void characterPlacement(Map &, const Persons &);
/// вычисляет урон нанесённый персонажу и возвращает true если он убит
bool takeDamage(Character &, const int damage);
/// проводит сражение если оно состоялось, возвращает true если герой погиб
bool battle(Persons &);
/// выводит информацию о персонажах
void printPersons(Persons &);
/// разведение по отличающимся координатам героя с персонажами
void separation (Persons &);
/// сохраняет игру
void saveGame(Persons &);
/// загружает игру
void loadGame(Map &, Persons &);

#endif // HEADER_H
