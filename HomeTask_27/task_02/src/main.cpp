#include <iostream>
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout << "Задание 2. Иерархия геометрических фигур" << endl;
  std::string command {""};
  cout << "Введите команду: ";
  cin >> command;
  double x, y; // центральные координаты

  if (command == "circle") {
    cout << "Введите радиус: ";
    double r;
    cin >> r;
    Circle c = Circle(r);
    c.setColor(Color::blue);
    cout << "Введите центральные координаты x, y: ";
    cin >> x >> y;
    c.setCoord(x, y);
    cout << "площадь круга = " << c.getArea() << endl;
    cout << "описывающий прямоугольник: ширина = " << c.getFrame().width
         << "  высота = " << c.getFrame().height << endl
         << "Координаты начала отрисовки (" << c.getFrame().coord.x << ":"
         << c.getFrame().coord.y << ")" << endl;
  } else  if (command == "square") {
    cout << "Введите длину ребра: ";
    double len;
    cin >> len;
    Square s = Square(len);
    s.setColor(Color::red);
    cout << "Введите центральные координаты x, y: ";
    cin >> x >> y;
    s.setCoord(x, y);
    cout << "площадь квадрата = " << s.getArea() << endl;
    cout << "описывающий прямоугольник: ширина = " << s.getFrame().width
         << "  высота = " << s.getFrame().height << endl
         << "Координаты начала отрисовки (" << s.getFrame().coord.x << ":"
         << s.getFrame().coord.y << ")" << endl;  }  else  if (command == "triangle") {
    cout << "Введите длину ребра: ";
    double len;
    cin >> len;
    Triangle t = Triangle(len);
    t.setColor(Color::green);
    cout << "Введите центральные координаты x, y: ";
    cin >> x >> y;
    t.setCoord(x, y);
    cout << "площадь равностороннего треугольника = " << t.getArea() << endl;
    cout << "описывающий прямоугольник: ширина = " << t.getFrame().width
         << "  высота = " << t.getFrame().height << endl
         << "Координаты начала отрисовки (" << t.getFrame().coord.x << ":"
         << t.getFrame().coord.y << ")" << endl;
  }  else  if (command == "rectangle") {
      cout << "Введите ширину и длину: ";
      double width, height;
      cin >> width >> height;
      Rectangle r = Rectangle(width, height);
      r.setColor(Color::non);
      cout << "Введите центральные координаты x, y: ";
      cin >> x >> y;
      r.setCoord(x, y);
      cout << "площадь прямоугольника = " << r.getArea() << endl;
      cout << "описывающий прямоугольник: ширина = " << r.getFrame().width
           << "  высота = " << r.getFrame().height << endl
           << "Координаты начала отрисовки (" << r.getFrame().coord.x << ":"
           << r.getFrame().coord.y << ")" << endl;
  } else {
    cout << "Введена неверная команда" << endl;
  }

  cout << "Программа завершила свою работу" << endl;

  return 0;
}

