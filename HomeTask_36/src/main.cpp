#include <QApplication>
#include "window.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  Window win;
  win.show();

  app.exec();
  return 0;
}
