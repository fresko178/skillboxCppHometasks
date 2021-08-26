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
      if (DO == (1 << (melody[i][j] - 48 - 1))) { cout << "DO "; }
      if (RE == (1 << (melody[i][j] - 48 - 1))) { cout << "RE "; }
      if (MI == (1 << (melody[i][j] - 48 - 1))) { cout << "MI "; }
      if (FA == (1 << (melody[i][j] - 48 - 1))) { cout << "FA "; }
      if (SOL == (1 << (melody[i][j] - 48 - 1))) { cout << "SOL "; }
      if (LA == (1 << (melody[i][j] - 48 - 1))) { cout << "LA "; }
      if (SI == (1 << (melody[i][j] - 48 - 1))) { cout << "SI "; }
    }
    cout << endl;
  }
}

