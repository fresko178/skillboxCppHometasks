#include <QApplication>
#include "form.h"
#include "ui_form.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  Form w;
  w.show();

  return app.exec();
}
