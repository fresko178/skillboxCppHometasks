#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
  cout << "Задание 4. Разработка детектора PNG-файла" << endl << endl;
  cout << "Введите путь к PNG файлу: ";
  string path;
  std::getline(cin, path);
  if (path.length() < 5) { exit(0); } // выходим если размер имени файла маловат
  if (path.substr(path.length() - 4) == ".png" || path.substr(path.length() - 4) == ".PNG") {
    std::ifstream file;
    file.open(path, std::ios::binary);
    if (file.is_open()) {
      char buf[4];
      file.read(buf, 4);
      if ((buf[0] == -119) && (buf[1] == 'P') && (buf[2] == 'N') && (buf[3] == 'G')) {
        cout << "файл явл. PNG - изображением";
      } else {
        cout << "файл НЕ явл. PNG - изображением";
      }
      file.close();
    } else {
      cout << "[ОШИБКА] Не удалось открыть файл для чтения" << endl;
      exit(EXIT_FAILURE);
    }
  } else {
    cout << "расширение файла не соответсвует PNG - изображению";
  }
  cout << endl << endl;
  return 0;
}

