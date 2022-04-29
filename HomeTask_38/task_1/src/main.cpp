/*
Задание 1. Добавление звука для кнопки
*/
#include <QtGui/QtGui>
#include <QApplication>

#include <QMediaPlayer>
#include <QPushButton>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  auto button = QPushButton("push me");
  button.resize(100, 25);
  auto *sound = new QMediaPlayer(&button);
  sound->setMedia(QUrl::fromLocalFile(QDir::currentPath() + "/test.wav"));
  sound->setVolume(20);
  QObject::connect(&button, &QPushButton::clicked, [sound](){ sound->play(); });
  button.show();
  return app.exec();
}

//#include "main.moc"

