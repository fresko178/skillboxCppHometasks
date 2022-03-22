#include "window.h"

Window::Window(QWidget *parent, int w, int h)
{
  setMinimumSize(w, h);
  slider.setOrientation(Qt::Horizontal);
  slider.setMinimumSize(100, 20);

  slider.setParent(this);
  slider.setMinimum(0);
  slider.setMaximum(100);
  image.setParent(this);
  layout.addWidget(&image);
  layout.addWidget(&slider);
  layout.addWidget(&spin);
  setLayout(&layout);

  connect(&slider, &QSlider::valueChanged, &spin, [this](int value)
  {
    QPixmap map = (value <= 33) ? image.mGreen : (value > 33 && value < 66) ? image.mYellow : image.mRed;
    image.setCurrentImage(map);
    spin.setValue(value);
  });

  connect(&spin, QOverload<int>::of(&QSpinBox::valueChanged), &slider, &QSlider::setValue);
}

Window::~Window()
{ }
