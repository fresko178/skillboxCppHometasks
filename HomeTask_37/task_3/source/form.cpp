#include "form.h"

// аргумент родительского виджета, инициализируем базовый класс
Form::Form(QWidget *parent) : QWidget(parent)
{
  setupUi(this);

  connect(pushButton_0, &QPushButton::clicked, this, &Form::slot_NumberChannel);
  connect(pushButton_1, &QPushButton::clicked, this, &Form::slot_NumberChannel);
  connect(pushButton_2, &QPushButton::clicked, this, &Form::slot_NumberChannel);
  connect(pushButton_3, &QPushButton::clicked, this, &Form::slot_NumberChannel);
  connect(pushButton_4, &QPushButton::clicked, this, &Form::slot_NumberChannel);
  connect(pushButton_5, &QPushButton::clicked, this, &Form::slot_NumberChannel);
  connect(pushButton_6, &QPushButton::clicked, this, &Form::slot_NumberChannel);
  connect(pushButton_7, &QPushButton::clicked, this, &Form::slot_NumberChannel);
  connect(pushButton_8, &QPushButton::clicked, this, &Form::slot_NumberChannel);
  connect(pushButton_9, &QPushButton::clicked, this, &Form::slot_NumberChannel);
  connect(pushButton_ChannelUp, &QPushButton::clicked, this, &Form::slot_channelUPDown);
  connect(pushButton_ChannelDown, &QPushButton::clicked, this, &Form::slot_channelUPDown);
  connect(pushButton_VolumeUp, &QPushButton::clicked, this, &Form::slot_volumeUPDown);
  connect(pushButton_VolumeDown, &QPushButton::clicked, this, &Form::slot_volumeUPDown);
  emit pushButton_1->clicked();
}

Form::~Form()
{ }

void Form::slot_NumberChannel()
{
  auto *button = static_cast<QPushButton *>(sender());
  setChannel(button->text().toInt());
  textEdit_Display->setText(QString("channel #%1   volume %2%").arg(getChannel()).arg(getVolume()));
}

void Form::slot_channelUPDown()
{
  auto *button = static_cast<QPushButton *>(sender());
  qint8 channel = getChannel();
  if (button->objectName() == "pushButton_ChannelUp") {
    if (channel == 9) { channel = -1; }
    textEdit_Display->setText(QString("channel #%1   volume %2%").arg(channel + 1).arg(getVolume()));
    setChannel(channel + 1);
  } else {
    if (channel == 0) { channel = 10; }
    textEdit_Display->setText(QString("channel #%1   volume %2%").arg(channel - 1).arg(getVolume()));
    setChannel(channel - 1);
  }
}

void Form::slot_volumeUPDown()
{
  auto *button = static_cast<QPushButton *>(sender());
  qint8 volume = getVolume();
  if (button->objectName() == "pushButton_VolumeUp") {
    if (volume < 100) {
      textEdit_Display->setText(QString("channel #%1   volume %2%").arg(getChannel()).arg(volume + 10));
      setVolume(volume + 10);
    }
  } else {
    if (volume > 0) {
      textEdit_Display->setText(QString("channel #%1   volume %2%").arg(getChannel()).arg(volume - 10));
      setVolume(volume - 10);
    }
  }
}

void Form::setChannel(qint8 numberChannel)
{
  this->numberChannel = numberChannel;
}

qint8 Form::getChannel()
{
  return numberChannel;
}

void Form::setVolume(qint8 levelVolume)
{
  this->levelVolume = levelVolume;
}

qint8 Form::getVolume()
{
  return levelVolume;
}

//  QScopedPointer<QPushButton> button(static_cast<QPushButton *>(sender()));
