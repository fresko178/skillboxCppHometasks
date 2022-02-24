#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QPushButton pb("Hello world");
  pb.resize(200, 100);
  pb.show();

  return app.exec();
}
