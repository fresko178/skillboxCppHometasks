#ifndef IMAGE_H
#define IMAGE_H

#include <QLabel>
#include <QPixmap>
#include <QPainter>

class Image : public QLabel
{
  QPixmap mCurrent;

  void paintEvent(QPaintEvent *e) override;

public:
  QPixmap mGreen;
  QPixmap mYellow;
  QPixmap mRed;

  Image(QWidget *parent = nullptr);
  ~Image();
  void setCurrentImage(QPixmap &);
};

#endif // IMAGE_H
