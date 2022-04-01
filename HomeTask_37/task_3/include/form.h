#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "ui_form.h"

class Form : public QWidget, public Ui_Form
{
  qint8 numberChannel {0};
  qint8 levelVolume {50};

public:
  explicit Form(QWidget *parent = nullptr);
  ~Form();
  void setChannel(qint8);
  qint8 getChannel();
  void setVolume(qint8);
  qint8 getVolume();

private slots:
  void slot_NumberChannel();
  void slot_channelUPDown();
  void slot_volumeUPDown();
};

#endif // FORM_H
