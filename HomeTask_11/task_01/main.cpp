#include <iostream>

using std::cout;
using std::cin;
using std::endl;

std::string encrypt_caesar(std::string, int);
std::string decrypt_caesar(std::string, int);
char getLetter(char, char, char, int);

int main() {
  std::string str = "";
  int shift = 0;
  cout << "Задание 1. Реализация шифра Цезаря" << endl;
  cout << "Введите кодируемую строку: ";
  std::getline(cin, str);
  cout << "Введите значение сдвига: ";
  cin >> shift;

  shift -= shift / 26 * 26; // избавляемся от циклов сдвига
  std::string encStr = encrypt_caesar(str, shift);
  cout << endl << encStr << endl;
  cout << endl << decrypt_caesar(encStr, shift) << endl;
  cout << endl;

  return 0;
}

std::string encrypt_caesar(std::string str, int shift) {
  for (size_t i = 0; i < str.length(); i++) {
    if (std::isupper(static_cast<int>(str[i]))) { // прописная буква
      str[i] = getLetter(str[i], 'A', 'Z', shift);
    } else if (std::islower(static_cast<int>(str[i]))) { // строчная буква
      str[i] = getLetter(str[i], 'a', 'z', shift);
    } else {
      ; // какой-то символ, не трогаем его
    }
  }

  return str;
}

// возвращает кодированный символ
// char letter - символ кондидат
// char borderDown - первый символ алфавита
// char borderUp - последний символ алфавита
// int shift - значение сдвига
char getLetter(char letter ,char borderDown, char borderUp, int shift) {
    if ((letter + shift) > borderUp) { // за пределами алфавита
      shift -= borderUp - letter;
      letter = static_cast<char>(borderDown + shift - 1); // кодированная буква
    } else if (letter + shift < borderDown) { // за пределами алфавита
      shift += letter - borderDown;
      letter = static_cast<char>(borderUp - -shift + 1);// кодированная буква
    } else {
      letter += shift;
    }

  return letter;
}

std::string decrypt_caesar(std::string str, int shift) {
    return encrypt_caesar(str, -shift);
}

