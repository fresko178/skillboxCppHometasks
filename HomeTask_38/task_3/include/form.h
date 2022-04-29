#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "ui_form.h"
#include <QFileDialog>
#include <QImage>

QImage blurImage(int blurRadius, QImage);

class Form : public QWidget, public Ui_Form
{
  QImage sourceImage;
//  QImage blurImage(int blurRadius);


public:

  explicit Form(QWidget *parent = nullptr);
  ~Form();
};

#endif // FORM_H
