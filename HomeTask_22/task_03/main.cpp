#include <iostream>
#include <map>
#include <string>
#include <string_view>

using std::endl;
using std::cout;
using std::cin;
using Word = std::map<char, int>;

void addToMap(Word &, const std::string_view &);
bool isAnagramma(const std::string_view &, const std::string_view &);

int main() {
  cout << "Задание 3. Анаграммы" << endl << endl;
  cout << "Введите первое слово: ";
  std::string str1 {""};
  cin >> str1;
  cout << "Введите второе слово: ";
  std::string str2 {""};
  cin >> str2;

  if (isAnagramma(str1, str2)) { cout << endl << "анаграмма" << endl; }
  else  { cout << endl << "НЕ анаграмма" << endl; }

  cout << endl << endl;
  return 0;
}

bool isAnagramma(const std::string_view &str1, const std::string_view &str2) {
  Word word1;
  Word word2;
  addToMap(word1, str1);
  addToMap(word2, str2);
  if (word1 == word2) { return true; }

  return false;
}

void addToMap(Word &word, const std::string_view &str) {
  for (char c : str) {
    word[c];
  }
}

