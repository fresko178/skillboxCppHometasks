#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using Vec = std::vector<string>;

void initialisationVec(string, Vec &vec);
size_t getPosition(size_t, size_t, Vec &);
void showQuestion(size_t, Vec &);
bool showAnswer(size_t, Vec &, string);

int main() {
  cout << "Задание 5. Реализация игры «Что? Где? Когда?»" << endl;
  Vec vecQuestions; // вектор секторов с вопросами
  Vec vecAnswer; // вектор ответов
  initialisationVec("question", vecQuestions);
  initialisationVec("answer", vecAnswer);
  size_t offset {0};
  size_t pos {1}; // позиция волчка
  string answer {""}; // ответ знатока
  size_t countConnoisseur {0};
  size_t countViewers {0};
  while(countConnoisseur < 6 && countViewers < 6) {
    cout << endl << "Введите offset: ";
    cin >> offset;
    if (offset < 1) {
      cout << "Сильней крутите волчок" << endl;
      continue;
    }
    pos = getPosition(pos, offset, vecQuestions);
    cout << "выпал сектор " << pos << endl;
    showQuestion(pos, vecQuestions);
    cout << endl << "ваш ответ: ";
    cin >> answer;
    if (showAnswer(pos, vecAnswer, answer)) {
      cout << "ответ верный" << endl;
      countConnoisseur++;
    } else {
      cout << "ответ НЕверный" << endl;
      countViewers++;
    }
    vecQuestions[pos - 1] = "";
  }
  if (countConnoisseur == 6) { cout << endl << "Победил знаток" << endl; }
  else { cout << endl << "Победили зрители" << endl; }
  cout << endl << endl;
  return 0;
}

void initialisationVec(string str, Vec &vec) {
  for (size_t i {1}; i <= 13; i++) {
    vec.push_back(str + std::to_string(i) + ".txt");
  }
}

// возвращает позицию волчка
size_t getPosition(size_t pos, size_t offset, Vec &vec) {
  pos += offset;
  while (pos > 13) { // сильно раскрутили волчок
    pos -= 13;
  }
  for(size_t i = 0; i < 13; i++) { // докручиваем волчок до сектора с неотвеченным вопросом
    if (vec[pos - 1] == "") { // на вопрос уже отвечали
      pos++; // сдвигаемся на соседний сектор
      if (pos > 13) { pos -= 13; } // волчок на следующем обороте
    } else { // попали на сектор с вопросом
      break; // позиция волчка найдена
    }
  }
  return  pos;
}

void showQuestion(size_t pos, Vec &vec) {
  std::ifstream file;
  file.open(vec[pos - 1]);
  if (file.is_open()) {
    string str {""};
    do {
      str = "";
      file >> str;
      if (str.length() > 0) { cout << str + " "; } // задаём вопрос
    } while(file.good());
    file.close();
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для чтения" << endl;
    exit(EXIT_FAILURE);
  }
}

// возвращает результат ответа знатока true ответ верный
bool showAnswer(size_t pos, Vec &vec, string answer) {
  std::ifstream file;
  file.open(vec[pos - 1]);
  if (file.is_open()) {
    string str {""};
    file >> str;
    if (str == answer) { return true; }
    file.close();
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для чтения" << endl;
    exit(EXIT_FAILURE);
  }
  return false;
}

