#include <iostream>
#include <array>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::array;

constexpr char FILLERSHIP {'O'};
constexpr char FILLERINIT {'.'};
constexpr int SIZE {10};
using Map = array<array<char, SIZE>, SIZE>;

void initialization(Map &, char);
void printMap(Map &); // выводит карту конкретного игрока
void printMaps(Map &gamer1, Map &gamer2); // выводит карты игроков
void setMap(Map &); // создаёт карту с флотом
void shipyard (Map &, size_t numDeck); // (верфь) устанавливает корабль на поле
bool checkCoord(size_t coorA, size_t coorB); // проверяет корректность введённой координаты
bool checkShip(Map &, size_t &coorA1, size_t &coorB1, size_t &coorA2, size_t &coorB2, size_t numDeck); // проверяет корректность введённого корабля
void orderForShips(Map &, size_t numDeck, int number, std::string msg); // создаёт необходимое кол. и типа корабли
bool playerTurn(Map &, char); // ход игрока
bool isRun(Map &); // определяет продолжение или окончание игры

int main() {
  cout << "Задача 9. Морской бой" << endl;
  Map map1; // создаём поле боя 1
  Map map2; // создаём поле боя 2
  initialization(map1, FILLERINIT); // запускаем рябь на море, чтобы лучше ориентироваться по координатам
  initialization(map2, FILLERINIT); // запускаем рябь на море, чтобы лучше ориентироваться по координатам
  cout << "Расположите корабли для игрока 1" << endl;
  setMap(map1);
  cout << endl << "-------------- OK! -------------- " << endl;
  cout << "Расположите корабли для игрока 2" << endl;
  setMap(map2);
  cout << endl << "-------------- OK! -------------- " << endl;
  cout << endl << endl << endl << endl << endl << endl << endl;
  printMaps(map1, map2);
  cout << endl << endl << "     Игра ничинается!" << endl;
  bool run {true}; // признак продолжения игры
  while (run) {
    while (!playerTurn(map2, '1')); // ход игрока 1
    printMaps(map1, map2); // вывод полей сражений игроков
    if (!isRun(map2)) { // выясняем победил ли игрок 1
      cout << endl << "ПОБЕДИТЕЛЬ Игрок 1" << endl;
      run = false;  // победитель выявлен, заканчиваем игру
    } else {
        while (!playerTurn(map1, '2')); // ход игрока 2
        printMaps(map1, map2); // вывод полей сражений игроков
        if (!isRun(map1)) { // выясняем победил ли игрок 2
          cout << endl << "ПОБЕДИТЕЛЬ Игрок 2" << endl;
          run = false;  // победитель выявлен, заканчиваем игру
        }
    }
  }
  cout << endl << endl;

  return 0;
}

void initialization(Map &map, char ch) {
  for (size_t row {0}; row < map.size(); row++) {
    for (size_t col {0}; col < map[row].size(); col++) {
      map[row][col] = ch;
    }
  }
}

void printMap(Map &map) {
  cout << "  ";
  for (size_t col {0}; col < map[0].size(); col++) { // вывод названия столбцов
    cout << std::right << std::setw(2) << "b" << col;
  }
  cout << endl;
  for (size_t row {0}; row < map.size(); row++) {
      cout << "a" << row; // вывод названия строк
    for (size_t col {0}; col < map[row].size(); col++) {
      cout << std::right << std::setw(3) << map[row][col]; // содержание карты
    }
    cout << endl;
  }
}

void printMaps(Map &map1, Map &map2) {
  cout << "Поле игрока 1:" << endl;
  printMap(map1);
  cout << endl << "Поле игрока 2:" << endl;
  printMap(map2);
}

void setMap(Map &map) {
//              палубы, кол.
  orderForShips(map, 1, 4, "Введите координаты для однопалубного корабля номер ");
  orderForShips(map, 2, 3, "Введите координаты для двупалубного корабля номер ");
  orderForShips(map, 3, 2, "Введите координаты для трёхпалубного корабля номер ");
  orderForShips(map, 4, 1, "Введите координаты для четырёхпалубного корабля номер ");
}

// map карта на которую наносится корабль
// numDeck число палуб коробля (тип)
void shipyard(Map &map, size_t numDeck) { // верфь
  bool good {false}; // признак некорректных данных
  size_t a1{0}, b1{0}, a2{0}, b2{0}; // координаты
  while (!good) {
    cin >> a1 >> b1;
    if (numDeck > 1) { // не однопалубник
      cin >> a2 >> b2;}
    else { // однопалубник
      a2 = a1;
      b2 = b1;
    }
    if (!checkShip(map, a1, b1, a2, b2, numDeck)) { // соответствует ли корабль и его расположение "госту"
      cout << "[ERROR] Введены некорректные данные корабля, повторите попытку" << endl;
    } else {
      good = true;
    }
  }
  for (size_t row = a1; row <= a2; row++) {
    for(size_t col = b1; col <= b2; col++) {
      map[row][col] = FILLERSHIP; // спускаем корабль наводу
    }
  }
}

// возвращает true если координаты корректные, в противном случае false
// a, b координаты
bool checkCoord(size_t a, size_t b) {
  return (a < SIZE && b < SIZE);
}

// Проверяет корректность введённого корабля
// &map карта на которую наносится корабль
// &a1, &b1 координаты начала корабля
// &a2, &b2 координаты конца корабля
// numDeck кол. палуб корабля (тип)
bool checkShip(Map &map, size_t &a1, size_t &b1, size_t &a2, size_t &b2, size_t numDeck) {
  if (!checkCoord(a1, b1) || !checkCoord(a2, b2)) { return false;} // пользователь ввёл некорректные данные
  if (a1 > a2) { std::swap(a1, a2); } // если первая координата старше второй
  if (b1 > b2) { std::swap(b1, b2); } // подправляем координаты, для этого по ссылке и передаём
  if ( !(((b1 == b2) && (a2 == a1 + numDeck - 1))
    || ((a1 == a2) && (b2 == b1 + numDeck - 1)))) { // корабль неправильной формы
    return false; // пользователь ввёл некорректные данные
  }
  for (size_t row = a1; row <= a2; row++) {
    for(size_t col = b1; col <= b2; col++) {
      if (map[row][col] == FILLERSHIP) { return false; } // вводимый корабль наплывает на существующий
    }
  }
  return true;
}

// Заказ необходимого кол. кораблей
// &map карта на которую наносится корабль
// numDeck кол. палуб корабля (тип)
// number кол. самих кораблей
// msg сообщение для пользователя
void orderForShips(Map &map, size_t numDeck, int number, std::string msg) {
  for (int num {1}; num <= number; num++) {
    cout << endl << msg << num << endl;
    shipyard(map, numDeck);
    printMap(map);
  }
}

// Ход игрока, определяет было ли попадание
// ch - символ номер игрока (имя)
// возвращает true если пользователь совершил ход удачно
//            false если пользователь не смог совершить ход
bool playerTurn(Map &map, char ch) {
    size_t row = 0, col = 0;
    cout << "Введите координаты выстрела для игрока '" << ch <<"': " << endl;
    cin >> row >> col;
    if (checkCoord(row, col)) {
      if (map[row][col] == FILLERSHIP) {
        cout << endl << "      Попадание!!!" << endl;
        map[row][col] = FILLERINIT;
      } else {
        cout << endl << "      Промах!" << endl;
      }
      return true;
    } else {
      row = col = 0;
      cout << "[ERROR]: Введены некорректные координаты, повторите ввод" << endl;
    }
  return false;
}

// определяет результат игры, её продолжение или окончание
// возвращает true если игра продолжается
//            false игра окончена
bool isRun(Map &map) {
  for(size_t row {0}; row < SIZE; row++) {
    for(size_t col {0}; col < SIZE; col++) {
      if (map[row][col] == FILLERSHIP) { return true; }
    }
  }
  return false;
}
