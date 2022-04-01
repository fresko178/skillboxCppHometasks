#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "ui_form.h"

class Form : public QWidget, public Ui_Form
{
public:

  explicit Form(QWidget *parent = nullptr);
  ~Form();

private slots:

  void slot_Addition();
  void slot_Subtraction();
  void slot_Multiplication();
  void slot_Division();

public slots:
  void funv();
};

#endif // FORM_H
