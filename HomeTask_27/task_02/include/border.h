#pragma once

enum Color {red, green, blue, non};

struct Coord {
  double x;
  double y;
};

struct Frame {
  Coord coord;
  double width;
  double height;
};

class Border {
  Coord coord;
  Color color;
  Frame frame;
  double data;
public:
  Border();
  ~Border();
  void setCoord(const double x, const double y);
  Coord getCoord() const;
  void setColor(Color);
  Color getColor() const;
  void setData(const double);
  double getData() const;
  Frame getFrame();
};

