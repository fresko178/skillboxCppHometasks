#include <QApplication>
#include "form.h"
#include "ui_form.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Form win;
  win.show();
  return app.exec();
}

//#include "main.moc"

