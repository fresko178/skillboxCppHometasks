#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QSpinBox>
#include "image.h"

class Window : public QWidget
{
  QSlider slider;
  Image image;
  QVBoxLayout layout;
  QSpinBox spin;

public:
  explicit Window(QWidget *parent = nullptr, int w = 200, int h = 200);
  ~Window();

private slots:
  void slot_setColor();
};

#endif // WINDOW_H
