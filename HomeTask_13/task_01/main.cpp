#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
  cout << "Задача 1. " << endl << endl;
  cout << "Введите кол. элементов: ";
  size_t size {0};
  cin >> size;

  if (size > 0) {
    cout << endl << "теперь сами элементы" << endl;
    vector<int> vec(size); // создаём вектор
    for (size_t i {0} ; i < size; i++) {
      cin >> vec[i]; // пользователь заполняет вектор
    }

    cout << endl << "введите значение которого не должно быть в векторе: ";
    int num {0};
    cin >> num;
    vector<int>::iterator i {vec.begin()};
    while (i != vec.end()) {
      if (*i == num) { vec.erase(i); }
      else { i++; }
    }

    cout << "в результате вектор: ";
    for (size_t i {0} ; i < vec.size(); i++) {
      cout << " " << vec[i]; // выводим вектор
    }
  } else {
    cout << endl << "Введено неверное кол. элементов";
  }

  cout << endl << endl;

  return 0;
}

