#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using Melody = std::vector<std::string>;

constexpr int SIZE {12};
enum {DO = 1, RE = 2, MI = 4, FA = 8, SOL = 16, LA = 32, SI = 64};
void Play(const Melody &);

int main() {
  cout << "Механическое пианино" << endl << endl;
  Melody melody;
  std::string notes {""}; // значение вводимое пользователем
  for (int i {1}; i <= SIZE; i++) {
    cout << "Введите композицию " << i << ": ";
    std::cin >> notes;
    melody.push_back(notes);
  }
  Play(melody);

  cout << endl << endl;
  return 0;
}

void Play(const Melody &melody) {
  for(size_t i {0}; i < SIZE; i++) {
    cout << i + 1 << ") ";
    for (size_t j {0}; j < melody[i].length(); j++) {
      switch (1 << (melody[i][j] - '0' - 1)) { // определяем цифру
        case DO: cout << "DO ";
          break;
        case RE: cout << "RE ";
          break;
        case MI: cout << "MI ";
          break;
        case FA: cout << "FA ";
          break;
        case SOL: cout << "SOL ";
          break;
        case LA: cout << "LA ";
          break;
        case SI: cout << "SI ";
          break;
      }
    }
    cout << endl;
  }
}

