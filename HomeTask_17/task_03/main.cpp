#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

bool isSubstring(char *, char *);

int main() {
  cout << "Задача 3." << endl << endl;
  char s1[] {"text1"};
  char s2[] {"ex"};
  char s3[] {"t1"};
  char s4[] {"text1"};
  char s5[] {"longtext1"};
  char s6[] {"qwe"};

  cout << "s1 = " << s1 << endl;
  cout << "s2 = " << s2 << endl;
  cout << "s3 = " << s3 << endl;
  cout << "s4 = " << s4 << endl;
  cout << "s5 = " << s5 << endl;
  cout << "s6 = " << s6 << endl;

  cout << "s1 = s2  " << isSubstring(s1, s2) << endl;
  cout << "s1 = s3  " << isSubstring(s1, s3) << endl;
  cout << "s1 = s4  " << isSubstring(s1, s4) << endl;
  cout << "s1 = s5  " << isSubstring(s1, s5) << endl;
  cout << "s1 = s6  " << isSubstring(s1, s6) << endl;
  cout << endl << endl;
  return 0;
}
// как работает:
// 1) искомая подстрока не может быть > строки иначе сразу возвращаем отрицательный результат
// 2) кол. сравнений строк = длина строки - длина подстроки, чтобы не делать лишних сравнений (экономим)
// 3) если подстрока нашлась раньше чем исчерпалось кол. сравнений - прекращаем поиск (экономим)
// 4) если при сравнении строк на текущем шаге сравнения хоть один символ не совпал - переходим на след. шаг (экономим)
bool isSubstring(char *originStr, char *subStr) {
  if (strlen(originStr) < strlen(subStr)) { return false; } // потенциальная подстрока не может быть больше оригинала
  bool match {true}; // признак одинаковые строки или нет (true одинаковые)
  size_t j {0}; // индекс подстроки
  for (size_t i {0}; i < strlen(originStr) - strlen(subStr) + 1; i++) { // проходим по строке за вычетом размера подстроки
    if (j == strlen(subStr) && match == true) { break; } // нашли подстроку, дальнейший поиск излишен
    match = true; // на каждом шаге сравнения считаем что строки совпадают
    j = 0;
    while (j < strlen(subStr)) { // сравниваем посимвольно строки
      if (subStr[j] != originStr[j + i]) { // ищем дальше
        match = false;
        break;
      }
      j++;
    }
  }
  return match;
}

