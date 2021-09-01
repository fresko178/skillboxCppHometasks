#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

bool isSubstring(char *, char *);
void print(char *arr);

int main() {
  cout << "Задача 2." << endl << endl;
  char s1[] {"text1"};
  char s2[] {"ex"};
  char s3[] {"t1"};
  char s4[] {"text1"};
  char s5[] {"longtext1"};
  char s6[] {"qwe"};

  cout << "s1 = ";
  print(s1);
  cout << "s2 = ";
  print(s2);
  cout << "s3 = ";
  print(s3);
  cout << "s4 = ";
  print(s4);
  cout << "s5 = ";
  print(s5);
  cout << "s6 = ";
  print(s6);
  cout << endl;
  cout << "s1 = s2  " << isSubstring(s1, s2) << endl;
  cout << "s1 = s3  " << isSubstring(s1, s3) << endl;
  cout << "s1 = s4  " << isSubstring(s1, s4) << endl;
  cout << "s1 = s5  " << isSubstring(s1, s5) << endl;
  cout << "s1 = s6  " << isSubstring(s1, s6) << endl;
  cout << endl << endl;
  return 0;
}

bool isSubstring(char *originStr, char *subStr) {
  if (strlen(originStr) < strlen(subStr)) { // потенциальная подстрока не может быть больше оригинала
    return false;
  }
  size_t steps = strlen(originStr) - strlen(subStr) + 1; // кол. сравнений
  for (size_t i {0}; i <= steps; i++) { // проходим по строке
    size_t end = i + strlen(subStr) - 1; // индекс последнего элемета выделяемой подстроки
    char str[end - i + 2]; // выделяемая подстрока
    str[end - i + 1] = '\0'; // последний элемент массива инициализируем нулём, чтобы получилась строка
    for (size_t j {0}; j < strlen(str); j++) { // выделяем подстроку из оригинальной строки
      str[j] = originStr[i + j];
    }
    if (strcmp(subStr, str) == 0) { // сравниваем строки
      return true;
    }
  }
  return false;
}

void print(char *str) {
  for (size_t i = 0; i < strlen(str); i++) {
    cout << str[i];
  }
  cout << endl;
}

