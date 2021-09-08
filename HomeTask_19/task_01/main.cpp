#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
  cout << "Задание 1. Разработка программы поиска слов в файле" << endl << endl;
  std::ifstream file;
  file.open("words.txt");
  if (file.is_open()) {
    cout << "Введите искомое слово: ";
    string strUser; // слово которое пользователь будет искать
    cin >> strUser;
    string str; // считываемая строка
    int count {0}; // счётчик найденных слов
    do {
      file >> str; // вычитываем строки из файла
      if (str == strUser) { count++; } // подсчитываем найденные строки
    } while (file.good()); // пока читать из файла удаётся
    cout << "кол. найденных слов = " << count << endl;
    file.close();
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для чтения" << endl;
    exit(EXIT_FAILURE);
  }

  cout << endl << endl;
  return 0;
}

