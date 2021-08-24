#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;

int main() {
  cout << "Спидометр" << endl;
  std::stringstream strBuffer; // отдельная строка буфер, требуемая по заданию
  strBuffer.setf(std::ios_base::fixed, std::ios_base::floatfield);
  strBuffer.precision(2); // два знака после запятой
  float currentSpeed = 0.0f;
  float val = 0.0f; // вводимое значение пользователем

  while(1) {
    cout << endl << "Ведите изменение в скорости: ";
    cin >> val;
    if ((currentSpeed + val) > 150.0f + 0.01f) { currentSpeed = 150.0f; } // быстрее движок не тянет
    else if ((currentSpeed + val) < 0.0f - 0.01f) { currentSpeed = 0.0f; } // скорость отрицательной не может быть
    else { currentSpeed += val; } // считаем скорость
    strBuffer.str(""); // очищаем буфер
    strBuffer << currentSpeed << " км/ч"; // заполняем буфер новыми данными
    cout << strBuffer.str(); // выводим содержимое буфера
    if ((currentSpeed >= 0.0f - 0.01f) && (currentSpeed <= 0.0f + 0.01f)) { break; } // приехали
  }
  cout << endl << endl;

  return 0;
}

