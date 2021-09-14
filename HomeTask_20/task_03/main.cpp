#include <iostream>
#include <fstream>
#include <string_view>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::string_view;

int fishing(const string_view &);

int main() {
  cout << "Задание 3. Реализация симуляции игры «Рыбалка»" << endl << endl;
  std::ofstream fileBasket("basket.txt", std::ios::app);
  if (fileBasket.is_open()) {
    cout << "выды рыб обитающих в водоёме: sunfish, shad, carp, bass, bullhead, walleye, catfish" << endl;
    string kindFish {""};
    int countFish {0}; // кол. пойманных рыб
    int sumFishes {0};
    char ch {'y'};
    while (ch == 'y' || ch == 'Y') { // рыбалка продолжается
      cout << endl << "Введите вид вылавливаемой рыбы: ";
      cin >> kindFish;
      sumFishes += countFish = fishing(kindFish);
      cout << "Поймано " << countFish << " шт." << endl;
      for (int i {0}; i < countFish; i++) {
        fileBasket << kindFish << endl;
      }
      cout << endl << "Хотите продолжить рыбалку? (Y/N): ";
      cin >> ch;
    }
    fileBasket.close();
    cout << endl << "Улов за текущую ловлю составляет " << sumFishes <<" шт." << endl;
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для записи" << endl;
    exit(EXIT_FAILURE);
  }
  return 0;
}

// возвращает кол. пойманных рыб
int fishing(const string_view &kindFish) {
  string fish {""}; // потенциально пойманная рыба
  int countFish {0}; // кол. пойманных рыб
  std::ifstream fileRiver("river.txt");
  if (fileRiver.is_open()) {
    do {
      fileRiver >> fish;
      if (fish == kindFish) { countFish++; }
      fish = "";
    } while (fileRiver.good()); // пока читать из файла удаётся
    fileRiver.close();
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для чтения" << endl;
    exit(EXIT_FAILURE);
  }
  return countFish;
}

