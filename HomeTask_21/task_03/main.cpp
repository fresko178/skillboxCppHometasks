#include <iostream>
#include <math.h>

struct Vector {
  double x {0.0};
  double y {0.0};
};

Vector getVector();
void add();
void subtract();
void scale();
void length();
void normalize();

using std::endl;
using std::cout;
using std::cin;

int main() {
  cout << "Задание 3. Реализация математического вектора" << endl << endl;
  std::string com {""}; // команда
  while (com != "add" && com != "subtract" && com != "scale" && com != "length" && com != "normalize") {
    cout << "Введите команду: ";
    cin >> com;
    if (com == "add") { add(); }
    if (com == "subtract") { subtract(); }
    if (com == "scale") { scale(); }
    if (com == "length") { length(); }
    if (com == "normalize") { normalize(); }
  }
  cout << endl << endl;
  return 0;
}

Vector getVector() {
  Vector v;
  cout << "введите координаты вектора (x, y): ";
  cin >> v.x >> v.y;
  return v;
}

void add() {
  Vector v1 = getVector();
  Vector v2 = getVector();
  cout << "сумма (" << v1.x + v2.x << " " <<  v1.y + v2.y << ")" << endl;
}

void subtract() {
  Vector v1 = getVector();
  Vector v2 = getVector();
  cout << "разность (" << v1.x - v2.x << " " <<  v1.y - v2.y << ")" << endl;
}

void scale() {
  Vector v = getVector();
  double s {0.0}; // скаляр
  cout << "Введите скаляр: ";
  cin >> s;
  cout << "результат (" << v.x * s << " " <<  v.y * s << ")" << endl;
}

void length() {
  Vector v = getVector();
  cout << "длина " << sqrt(v.x * v.x + v.y * v.y) << endl;
}

void normalize() {
  Vector v = getVector();
  double d = sqrt(v.x * v.x + v.y * v.y);
  cout << "результат (" << v.x / d << " " << v.y / d << ")" << endl;
//  cout << "проверка " << (v.x / d) * (v.x / d) + (v.y / d) * (v.y / d) << endl;
}

