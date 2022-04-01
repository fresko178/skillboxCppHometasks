#include "form.h"

// аргумент родительского виджета, инициализируем базовый класс
Form::Form(QWidget *parent) : QWidget(parent)
{
  setupUi(this);
  connect(pushButton_Additional, &QPushButton::clicked, this, &Form::slot_Addition);
  connect(pushButton_Subtraction, &QPushButton::clicked, this, &Form::slot_Subtraction);
  connect(pushButton_Multiplication, &QPushButton::clicked, this, &Form::slot_Multiplication);
  connect(pushButton_Division, &QPushButton::clicked, this, &Form::slot_Division);
}

Form::~Form()
{ }

void Form::slot_Addition()
{
  lineEdit_Answer->setText(QString().number(spinBox_Number1->value() + spinBox_Number2->value(), 10));
}

void Form::slot_Subtraction()
{
  lineEdit_Answer->setText(QString().number(spinBox_Number1->value() - spinBox_Number2->value(), 10));
}

void Form::slot_Multiplication()
{
  lineEdit_Answer->setText(QString().number(spinBox_Number1->value() * spinBox_Number2->value(), 10));
}

void Form::slot_Division()
{
  lineEdit_Answer->setText(QString().number(spinBox_Number1->value() / spinBox_Number2->value(), 10));
}
