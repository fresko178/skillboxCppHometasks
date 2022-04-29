#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "ui_form.h"

class Form : public QWidget, public Ui_Form
{
public:

  explicit Form(QWidget *parent = nullptr);
  ~Form();
};

#endif // FORM_H
