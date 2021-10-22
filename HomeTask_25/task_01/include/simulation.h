#pragma once
#include <string>

typedef struct {
  double x {0};
  double y {0};
} Point;

/// координаты p1 начало разреза p2 конец разреза
void scalpel(Point &p1, Point &p2);

/// p координата применения зажима
void hemostat(Point &p);

/// p координата применения пинцета
void tweezers(Point &p);

/// координаты p1 начало зашивания p2 конец зашивания иглой
void suture(Point &p1, Point &p2);

/// возвращает координаты Point{x, y}
Point enterCoord(const std::string &text);

/// возвращает true если координата лежит на прямой, иначе false
/// s - координата начала прямой
/// e - координата конца прямой
/// n - координата проверяемой точки
bool checkCoord(Point &s, Point &e, Point &n);
