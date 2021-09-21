#include <iostream>
#include <vector>
#include <string_view>

enum typeBuilding {HOME = 1, GARAGE, BARN, BATHHOUSE};
enum typeRoom {BEDROOM = 1, KITCHEN, BATHROOM, CHILDREN, LIVINGROOM};

struct Room {
  unsigned int area {0}; // площадь комнаты
  typeRoom type; // тип комнаты
};

struct Floor {
  public:
    unsigned int setCountRooms(const unsigned int &countRooms) {
      if(countRooms > 1 && countRooms < 5) { return this->countRooms = countRooms; }
      return 0;
    }

    unsigned int getCountRooms() {
      return countRooms;
    }

    unsigned long setRoom(Room &r) {
      if (room.size() <= countRooms) { // кол. комнат не превышает максимум (2-4)
        room.push_back(r);
        return room.size(); // возвращаем номер созданной комнаты
      }
      return 0; // комната не создалась т.к. под новые нет места
    }

    unsigned int hight {0}; // ограничения на высоту потолка требованием не накладывается

  private:
    std::vector<Room> room;
    unsigned int countRooms {0};
};

struct Building {
  public:
    unsigned int setCountFloors(const unsigned int &countFloors) {
      if(countFloors > 0 && countFloors < 4) { return this->countFloors = countFloors; }
      return 0; // если указано недопустимое кол. этажей
    }

    unsigned int getCountFloors() {
      return countFloors;
    }

    unsigned long setFloor(Floor &f) {
      if (floor.size() <= countFloors) { // кол. этажей не превышает максимум (1-3)
        floor.push_back(f);
        return floor.size(); // возвращаем номер созданного этажа
      }
      return 0; // этаж не создался т.к. под новые нет места
    }

    bool setFurnace(bool f) {
      if (type == HOME || type == BATHHOUSE) { return furnace = f; }
      return false; // если предпринимается попытка установить печь в гараже или сарае
    }

    bool getFurnace() {
      return furnace;
    }

    typeBuilding type; // тип здания
    unsigned int area {0}; // площадь здания занимаемая на участке

  private:
    std::vector<Floor> floor;
    unsigned int countFloors {0};
    bool furnace {false};
};

struct Area {
  int number {0}; // номер участка
  std::vector<Building> buildings; // постройки на участке
};

typeBuilding setTypeBuilding();
typeRoom setTypeRoom();
unsigned int getArea(const std::string_view &); // ввод площади
void buildingConstruction(Building &b); // строительство здания
void setFurnace(Building &); // установка печи
bool isHome(std::vector<Building> &); // выводит наличие или отсутствие обязательной постройки (дом)

using std::endl;
using std::cout;
using std::cin;

//--------------------------------------------------------------------------------------------
int main() {
  cout << "Задание 2. Модель данных для посёлка" << endl << endl;
  cout << "Введите общее кол. участков в посёлке: " << endl;
  int countArea;
  cin >> countArea; // кол. участков
  std::vector<Area> village; // вот моя деревня, вот мой край родной
  for (int i {0}; i < countArea; i++) {
    Area newArea;
    newArea.number = i + 1; // номер участка
    cout << "Введите общее кол. построек на участке " << newArea.number << ":" << endl;
    int countBuildings;
    cin >> countBuildings; // кол. построек
    for (int i {0}; i < countBuildings; i++) {
      cout << "Участок " << newArea.number << " здание " << i + 1 << endl;
      Building newBuilding;
      buildingConstruction(newBuilding);
      newArea.buildings.push_back(newBuilding);
    }
    while (!isHome(newArea.buildings)) { // пока пользователь не введёт обязательную постройку дом
      cout << "Не введены данные обязательной постройки \"Дом\"" << endl;
      Building newBuilding;
      buildingConstruction(newBuilding);
      newArea.buildings.push_back(newBuilding);
    }
    village.push_back(newArea);
  }

  unsigned int sumArea {0};
  for(auto v : village) {
    for (auto b : v.buildings) {
      sumArea += b.area;
    }
  }
  cout << endl << "Общая площадь зданий = " << sumArea;
  cout << endl << endl;
  return 0;
}
//--------------------------------------------------------------------------------------------

typeBuilding setTypeBuilding() {
  typeBuilding type {HOME};
  int var {0};
  while (var < 1 || var > 4) {
    cout << "Выберите тип постройки введя номер пункта из списка:" << endl <<
            "1) дом" << endl << "2) гараж" << endl << "3) сарай" << endl << "4) баня" << endl;
    cin >> var;
    switch(var) {
      case 1 : type = HOME;
        break;
      case 2 : type = GARAGE;
        break;
      case 3 : type = BARN;
        break;
      case 4 : type = BATHHOUSE;
        break;
      default: cout << "[ОШИБКА] Указан неверный пункт повторите ввод" << endl;
    }
  }
  return type;
}

typeRoom setTypeRoom() {
  typeRoom type {BEDROOM};
  int var {0};
  while (var < 1 || var > 5) {
    cout << "Выберите тип комнаты введя номер пункта из списка:" << endl <<
            "1) спальня" << endl << "2) кухня" << endl << "3) ванная" << endl <<
            "4) детская" << endl << "5) гостиная" << endl;
    cin >> var;
    switch(var) {
      case 1 : type = BEDROOM;
        break;
      case 2 : type = KITCHEN;
        break;
      case 3 : type = BATHROOM;
        break;
      case 4 : type = CHILDREN;
        break;
      case 5 : type = LIVINGROOM;
        break;
      default: cout << "[ОШИБКА] Указан неверный пункт повторите ввод" << endl;
    }
  }
  return type;
}

unsigned int getArea(const std::string_view &str) {
  cout << str << endl;
  unsigned int area;
  cin >> area;
  return area;
}

void setFurnace(Building &b) {
  cout << "Устанавливать печь? (y/n): ";
  char ch;
  cin >> ch;
  if (ch == 'y' || ch == 'Y') { b.setFurnace(true); }
}

void buildingConstruction(Building &newBuilding) {
  newBuilding.type = setTypeBuilding();
  newBuilding.area = getArea("Введите площадь здания: ");
  if (newBuilding.type == HOME || newBuilding.type == BATHHOUSE) {
    setFurnace(newBuilding);
  }
  unsigned int countFloors {0};
  while (countFloors < 1 || countFloors > 3) {
    cout << "Введите кол. этажей в здании (от 1 до 3)";
    cin >> countFloors;
    if (countFloors < 1 || countFloors > 3) {
      cout << "[ОШИБКА] Введено неверное кол. этажей, повторите ввод" << endl;
    }
  }
  newBuilding.setCountFloors(countFloors); // кол. этажей
  for (unsigned int i {0}; i < countFloors; i++) {
    Floor newFloor;
    cout << "Введите высоту потолка этажа " << i + 1 << ":";
    cin >> newFloor.hight;
    unsigned int countRooms {0};
    while (countRooms < 2 || countRooms > 4) {
      cout << "Введите кол. комнат (от 2 до 4)";
      cin >> countRooms;
      if (countRooms < 2 || countRooms > 4) {
        cout << "[ОШИБКА] Введено неверное кол. комнат, повторите ввод" << endl;
      }
    }
    newFloor.setCountRooms(countRooms); // кол. комнат
    for (unsigned int i {0}; i < countRooms; i++) {
      Room newRoom;
      newRoom.type = setTypeRoom();
      newRoom.area = getArea("Введите площадь комнаты " + std::to_string(i + 1) + ":");
      newFloor.setRoom(newRoom);
    }
    newBuilding.setFloor(newFloor);
  }
}

bool isHome(std::vector<Building> &buildings) {
  for(auto &b : buildings) {
    if (b.type == HOME) { return true; }
  }
  return false;
}

