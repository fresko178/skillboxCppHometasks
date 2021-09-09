#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

int main() {
  cout << "Задание 3. Реализация программы чтения ведомости" << endl << endl;
  std::ifstream file;
  file.open("file.txt");
  if (file.is_open()) {
    string name {""}; // полное имя человека
    string maxName {""}; // имя человека с максимальной выплатой
    string str {""};
    double maxMoney {0}; // максимальная выплата
    double sum {0};   // сумма выплат
    do {
      name = "";
      str = "";
      file >> str; // имя
      if (str.length() > 0) { // если считали не пустую строку значит есть ещё что вычитывать
        name += str;
        file >> str; // фамилия
        name += " " + str;
        file >> str; // выплата
        if (std::stod(str) > maxMoney) { // максимальная сумма выплаты
          maxMoney = std::stod(str);
          maxName = name;
        }
        sum += std::stod(str); // посчитываем сумму выплат
        file >> str; // вычитываем дату (нигде не использующуюся)
      }
    } while (file.good()); // пока читать из файла удаётся
    file.close();
    cout << "сумма выплат = " << sum << endl;
    cout << "максимальная выплата " << maxName << "  " << maxMoney << endl;
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для чтения" << endl;
    exit(EXIT_FAILURE);
  }

  cout << endl << endl;
  return 0;
}

