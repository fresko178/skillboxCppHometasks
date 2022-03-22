#include "image.h"

Image::Image(QWidget *parent)
{
  setParent(parent);
  mGreen.load("green.png");
  mYellow.load("yellow.png");
  mRed.load("red.png");
  mCurrent = mGreen;
  this->setMinimumSize(mCurrent.rect().size());
}

Image::~Image()
{ }

void Image::paintEvent(QPaintEvent *e)
{
  QPainter pa(this);
  pa.drawPixmap(mCurrent.rect(), mCurrent);
}

void Image::setCurrentImage(QPixmap &pm)
{
  mCurrent = pm;
  update();
}
