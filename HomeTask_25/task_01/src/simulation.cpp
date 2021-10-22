#include <iostream>
#include "simulation.h"

using std::cout;
using std::endl;
using std::cin;

void scalpel(Point &p1, Point &p2) {
  cout << "Был сделан разрез от точки " << p1.x << ":" << p1.y
       << " до точки " << p2.x << ":" << p2.y << endl;
}

void suture(Point &p1, Point &p2) {
  cout << "Был сделан шов от точки " << p1.x << ":" << p1.y
       << " до точки " << p2.x << ":" << p2.y << endl;
}

void hemostat(Point &p) {
  cout << "Был применён зажим в точке " << p.x << ":" << p.y << endl;
}

void tweezers(Point &p) {
  cout << "Был применён пинцет в точке " << p.x << ":" << p.y << endl;
}

Point enterCoord(const std::string &text) {
  cout << text << endl;
  Point p;
  cout << "Введите x: ";
  cin >> p.x;
  cout << "Введите y: ";
  cin >> p.y;
  return p;
}

bool checkCoord(Point &s, Point &e, Point &n) {
  if(0 == (n.x - s.x) * (e.y - s.y) - (e.x - s.x) * (n.y - s.y)
    && (n.x >= s.x && n.x <= e.x)
    && (n.y >= s.y && n.y <= e.y)) {
    return true;
  }
return false;
}

// формула
//  x - x1    y - y1
//  ------- = -------
//  x2 - x1   y2 - y1
// избавляемся от деления
//  (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1) = 0
