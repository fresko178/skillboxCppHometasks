#include <iostream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum {
  HOME        =  1, // автомат вкл./выкл. всего дома
  SOCKETS     =  2, // автомат основные розетки дома
  LIGHT_IN    =  4, // автомат свет внутри дом
  LIGHT_OUT   =  8, // автомат наружный свет в саду
  HEATING_IN  = 16, // автомат отопление в помещении
  HEATING_OUT = 32, // автомат отопление водопровода
  CONDITIONER = 64  // автомат кондиционер в помещении
};

int main() {
  cout << "Умный дом" << endl << endl;
  int temp_in     {0};    // датчик температуры внутри  в цельсиях
  int temp_out    {0};    // датчик температуры снаружи в цельсиях
  int temp_light  {5000}; // температура цвета в Кельвинах
  string move     {""};   // датчик движения
  string home     {""};   // электричество самого дома
  string sockets  {""};   // розетки
  string light_in {""};   // свет в доме
  std::stringstream buffer;
  string str = ""; // строка которую вводит пользователь с данными
  int switchBox = 0; // наш электро-щиток
  for (int hours = {0}, days {1}; days <= 2; hours++) {
    cout << endl << endl;
    cout << "время " << hours << ":00 введите данные "
            "[темп.сн.]  [темп.вн.]  [движение(y/n)]  [элек.Дома(on/off)]  [розетки(on/off)]  [свет в доме(on/off)]" << endl;
    std::getline(cin, str);
    buffer << str;
// парсим
    buffer >> str;      // температуру снаружи
    temp_out = std::stoi(str);
    buffer >> str;      // температуру в доме
    temp_in = std::stoi(str);
    buffer >> move;     // наличие/отсутствие движения
    buffer >> home;     // вкл./откл. электричества дома
    buffer >> sockets;  // вкл./откл. розеток
    buffer >> light_in; // вкл./откл. свет в доме
    buffer.clear();

    if (home == "on") { // система умный дом работает
      if (!(switchBox & HOME)) {
        switchBox |= HOME;
        cout << endl << "Включена система умный дом";
      }

      if (temp_out < 0) {
        if (!(switchBox & HEATING_OUT)) {
          switchBox |= HEATING_OUT;
          cout << endl << "Включен обогрев водопровода";
        }
      } else if (temp_out > 5) {
        if ((switchBox & HEATING_OUT)) {
          switchBox &= ~HEATING_OUT;
          cout << endl << "Выключен обогрев водопровода";
        }
      }

      if (move == "y") { cout << endl << "Achtung, alarm! Движение YES"; }
      else {cout << endl << "Движение NO";}

      if ((hours > 16 || hours < 5) && move == "y") {
        if (!(switchBox & LIGHT_OUT)) {
          switchBox |= LIGHT_OUT;
          cout << endl << "Включен наружный свет в саду";
        }
      } else {
        if ((switchBox & LIGHT_OUT)) {
          switchBox &= ~LIGHT_OUT;
          cout << endl << "Выключен наружный свет в саду";
        }
      }

      if (temp_in < 22) {
        if (!(switchBox & HEATING_IN)) {
          switchBox |= HEATING_IN;
          cout << endl << "Включено отопление в доме";
        }
      } else if (temp_in >= 25) {
        if ((switchBox & HEATING_IN)) {
          switchBox &= ~HEATING_IN;
          cout << endl << "Выключено отопление в доме";
        }
      }

      if (sockets == "on") {
        if (!(switchBox & SOCKETS)) {
          switchBox |= SOCKETS;
          cout << endl << "Включены розетки";
        }
      } else {
        if ((switchBox & SOCKETS)) {
          switchBox &= ~SOCKETS;
          cout << endl << "Выключены розетки";
        }
      }

      if ((temp_in >= 30) && (switchBox & SOCKETS)) {
        if (!(switchBox & CONDITIONER)) {
          switchBox |= CONDITIONER;
          cout << endl << "Включен кондиционер";
        }
      } else if (temp_in <= 25) {
        if (switchBox & CONDITIONER) {
          switchBox &= ~CONDITIONER;
          cout << endl << "Выключен кондиционер";
        }
      }

      if (light_in == "on") {
        if (!(switchBox & LIGHT_IN)) {
          switchBox |= LIGHT_IN;
          cout << endl << "Включен свет в доме";
        }
      } else if (temp_in <= 25) {
        if ((switchBox & LIGHT_IN)) {
          switchBox &= ~LIGHT_IN;
          cout << endl << "Выключен свет в доме";
        }
      }

      if ((hours >= 16 && hours < 21) && (switchBox & LIGHT_IN)) {
        temp_light = 5000 - (hours - 16 + 1) * 460; // расчитываем освещённость
        cout << endl << "освещённость теперь " << temp_light << "K";
      } else if (hours == 0) {
        temp_light = 5000; // освещённость поумолчанию
        if (switchBox & LIGHT_IN) { cout << endl << "освещённость теперь " << temp_light << "K"; }
      }

    } else {
      if (switchBox & HOME) {
        switchBox &= ~HOME;
        cout << endl << "Выключена система умный дом";
      }
      cout << endl << "Cистема умный дом не работает - отключено электричество";
    }

    if (23 == hours) { // 24 час это уже след. день
      days++;
      hours = -1;
    }
  } // for end

  cout << endl << endl;
  return 0;
}

