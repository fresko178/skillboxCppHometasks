#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

constexpr int SIZE {10};

int main() {
  cout << "Задание 2. Разработка просмотрщика текстовых файлов" << endl << endl;
  cout << "Введите путь к текстовому файлу: ";
  string path;
  std::getline(cin, path);
  std::ifstream file;
  file.open(path, std::ios::binary);
  if (file.is_open()) {
    char buf[SIZE];
    do {
      file.read(buf, SIZE - 1);
      buf[file.gcount()] = '\0'; // превращаем в строку
      cout << buf;
    } while (file.good()); // пока читать из файла удаётся
    file.close();
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для чтения" << endl;
    exit(EXIT_FAILURE);
  }

  cout << endl << endl;
  return 0;
}

