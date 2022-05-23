#include "form.h"
#include <QRegularExpression>

// аргумент родительского виджета, инициализируем базовый класс
Form::Form(QWidget *parent) : QWidget(parent)
{
  setupUi(this);
  QRegularExpression exp("^\\+\\d[0-9]{10}$");
  connect(lineEdit, &QLineEdit::textChanged, this, [this, exp](QString str)
  {
    if (exp.match(str).hasMatch()) {
      label_result->setStyleSheet("color: green;");
      label_result->setText("[ OK ]");
    } else {
      label_result->setStyleSheet("color: red;");
      label_result->setText("[FAIL]");
    }
  });
}

Form::~Form()
{ }

